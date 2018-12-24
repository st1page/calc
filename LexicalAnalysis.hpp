#include "token.h"

#include <string>
#include <vector>
#include <queue>
class LexicalAnalysis{
private:
	enum State{ Normal, Identifier, Number, Sign, Space};	
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

				break;
			case Identifier:

				break;
			case Number:

				break; 
			case Sign:

				break;
			case Space:

				break;
		}	
		if(type) newToken(type);
	}
public:

};
 