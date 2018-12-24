#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

#define NAME		5	
#define NUMBER		6
#define STRING		7

#define EQUAL		8  //	=

#define LPAR		13 //	( parentheses
#define RPAR		14 //	)
#define LSQB 		15 //	[
#define RSQB		16 //	]

#define PLUS		17 //	+
#define MINUS		18 //	-
#define STAR		19 //	*
#define DOUBLESTAR	20 //	**
#define SLASH		21 //	/
#define DOUBLESLASH	22 //	//
#define PERCENT		23 //	%

#define VBAR		24 //	| vertical bar
#define AMPER		25 //	& ampersand
#define TILDE		26 //	~
#define CIRCUMFLEX	27 //	^
#define LSH			28 //	<<
#define RSH			29 //	>>  

#define LESS		30 //	<
#define GREATER		31 //	>
#define EQUALEQ		32 //	==
#define NOTEQ		33 //	!=
#define LESSEQ		34 //	<=
#define GREATEREQ	35 //	>=

#define DOLLAR		36 //	$

#define AND			37 //	&&
#define OR			38 //	||
#define NOT			39 //	!

#define RARROW		40 //	=>

#define ENDSYMBOL	63

struct Token{
	unsigned char type;
	std::string data;
	Token(unsigned char t,std::string &d){
		type = t;
		data = d;
	}
	~Token(){
		std::string().swap(data);	
	}
};
#endif