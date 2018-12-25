#ifndef _MYCTYPE_HPP_
#define _MYCTYPE_HPP_

#include <cctype>
#include "token.h"

inline bool isIdentStart(char c){
	return isalpha(c)||(c=='_');
} 
inline bool isIdent(char c){
	return isalpha(c)||isdigit(c)||(c=='_');
} 
inline bool isSignStart(char c){
	switch(c){
		case '=': 
		case '(': 
		case ')': 
		case '[': 
		case ']': 
		case '+': 
		case '-': 
		case '*':
		case '/':
		case '%':
		case '|': 
		case '&': 
		case '~': 
		case '^':
		case '<':
		case '>':
		case '$':
		case '!': return true;
	} return false;
}
inline unsigned char signType(char c){
	switch(c){
		case '=': return EQUAL; break;
		case '(': return LPAR; break;
		case ')': return RPAR; break;
		case '[': return LSQB; break;
		case ']': return RSQB; break;
		case '+': return PLUS; break;
		case '-': return MINUS; break;
		case '*': return STAR; break;
		case '/': return SLASH; break;
		case '%': return PERCENT; break;
		case '|': return VBAR; break;
		case '&': return AMPER; break;
		case '~': return TILDE; break;
		case '^': return CIRCUMFLEX; break;
		case '<': return LESS; break;
		case '>': return GREATER; break;
		case '$': return DOLLAR; break;
		case '!': return NOT; break;
	}
	return 0;
}
inline unsigned char doubleSignType(char c1,char c2){
	switch(c1){
		case '*':
			if(c2=='*') return DOUBLESTAR;
			break;
		case '/':
			if(c2=='/') return DOUBLESLASH;
			break;
		case '<':
			if(c2=='<') return LSH;
			if(c2=='=') return LESSEQ;
			break;
		case '>':
			if(c2=='>') return RSH;
			if(c2=='=') return GREATEREQ;
			break;
		case '=':
			if(c2=='>') return RARROW;
			if(c2=='=') return EQUALEQ;
			break;
		case '!':
			if(c2=='=') return NOTEQ;
			break;
		case '&':
			if(c2=='&') return AND;
			break;
		case '|':
			if(c2=='|') return OR;
			break;
	}
	return 0;
}
#endif