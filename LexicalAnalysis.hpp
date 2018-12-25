#ifndef _LEXICALANALTSIS_HPP_
#define _LEXICALANALTSIS_HPP_

#include "token.h"
#include "myctype.hpp"
#include "MyException.hpp"

#include <cctype>

#include <string>
#include <vector>
#include <queue>


class LexicalAnalysis{
private:
	enum State{ Normal, Identifier, Number, NumberP, NumberE, Sign};	
	State state;
	std::string readBuffer;
	std::queue<Token> tokenBuffer;

	~LexicalAnalysis(){
		std::string().swap(readBuffer);	
		std::queue<Token>().swap(tokenBuffer);	
	}
	bool empty(){
		return tokenBuffer.empty();
	}
	Token outToken(){
		Token token = tokenBuffer.front();
		tokenBuffer.pop();
		return token;
	}
	void newToken(unsigned char type){
		tokenBuffer.push(Token(type,readBuffer));
		std::string().swap(readBuffer);	
	}
	void inChar(char x){
		unsigned char type = 0;
		switch(state){
			case Normal:
				if(isIdentStart(x)){
					state = Identifier;
					readBuffer.push_back(x);
				} else if(isSignStart(x)){
					state = Sign;
					readBuffer.push_back(x);
				} else if(isdigit(x)){
					state = Number;
					readBuffer.push_back(x);
				} else if(isspace(x)){
					break;
				} else {
					throw lexicalException();	
				}
				break; 
			case Identifier:
				if(isIdent(x)){
					readBuffer.push_back(x);
				} else {
					newToken(IDENT);
					state = Normal;
					inChar(x);
				}
				break;
			case Number:
				if(isdigit(x)){
					readBuffer.push_back(x);
				} else if(x=='.'){
					state = NumberP;
					readBuffer.push_back(x);
				} else if(x=='e'||x=='E'){
					state = NumberE;
					readBuffer.push_back(x);
				} else {
					newToken(NUMBER);
					state = Normal;
					inChar(x);
				}
				break; 
			case NumberP:
				if(isdigit(x)){
					readBuffer.push_back(x);
				} else if(x=='e'||x=='E'){
					state = NumberE;
					readBuffer.push_back(x);
				} else {
					newToken(NUMBER);
					state = Normal;
					inChar(x);
				}
				break;
			case NumberE:
				if(isdigit(x)){
					readBuffer.push_back(x);
				} else if(x=='-'){
					char c = readBuffer.back();
					if(c == 'E' || c == 'e') {
						readBuffer.push_back(x);
					} else {
						newToken(NUMBER);
						state = Normal;
						inChar(x);
					}
				} else {
					newToken(NUMBER);
					state = Normal;
					inChar(x);
				}
				break;
			case Sign:
				char c = readBuffer.back();
				if(doubleSignType(c,x)){
					newToken(doubleSignType(c,x));
					state = Normal;
					inChar(x);
				} else {
					if(!signType(c))
					newToken(signType(c));
					state = Normal;
					inChar(x);
				}
				break;
		}	
		if(type) newToken(type);
	}
public:

};
#endif