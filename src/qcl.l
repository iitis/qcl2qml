%{
#include "qcl.tab.h"
#include <string>

using namespace std;




string strbuff;
string srcname;

%}

%option prefix="qcl"
%option noyywrap
%option yylineno
%option nounput
%x comm comm1 strng

/*  */
ALPHA [a-zA-Z]
DIGIT [0-9]
ALNUM {ALPHA}|{DIGIT}

ID {ALPHA}{ALNUM}*


%%

{DIGIT}+		{ yylval.INT=atoi(yytext); return tokCONSTI;}   
{DIGIT}+(\.{DIGIT}*)	{ yylval.REAL=atof(yytext);  return tokCOMPLEX_COORD;}

"int"			{ return tokINT; }
"real"			{ return tokREAL; }
"complex"		{ return tokCOMPLEX; }
"boolean"		{ return tokBOOLEAN ;}
"string"		{ return tokSTRING ;}
"qureg"			{ return tokQUREG ;}
"quvoid"		{ return tokQUVOID ;}
"quconst"		{ return tokQUCONST ;}
"quscratch"		{ return tokQUSCRATCH ;}

"true"			{ return tokTRUE;}
"false"			{ return tokFALSE; }

"mod"			{ return tokMOD; }
"=="			{ return tokEQ; }
"!="			{ return tokNEQ; }
"<="			{ return tokLORE;}
">="			{ return tokGORE; }
"not"			{ return tokNOT; }
"and"			{ return tokAND; }
"or"			{ return tokOR; }
"xor"			{ return tokXOR; }

"for"			{ return tokFOR; }
"to"			{ return tokTO; }
"step"			{ return tokSTEP; }
"while"			{ return tokWHILE; }
"until"			{ return tokUNTIL; }
"if"			{ return tokIF; }
"else"			{ return tokELSE; }
"return"		{ return tokRETURN; }
"input"			{ return tokINPUT; }
"print"			{ return tokPRINT ;}
"exit"			{ return tokEXIT; }
"measure"		{ return tokMEASURE; }
"reset"			{ return tokRESET; }
"dump"			{ return tokDUMP; }
"list"			{ return tokLIST; }
"load"			{ return tokLOAD; }
"save"			{ return tokSAVE; }
"shell"			{ return tokSHELL; }


"procedure"		{ return tokPROCEDURE; }
"operator"		{ return tokOPERATOR; }
"qufunct"		{ return tokQUFUNCT; }


".."			{ return tokMULTDOT;}

 \"			{ BEGIN(strng); strbuff.erase();}
<strng>\"		{ BEGIN 0 ; 
			  yylval.STRING = &strbuff;  
			  return tokSTRINGCONST;
			}
<strng>.		{ strbuff+=yytext;}

"//"			{ BEGIN(comm);}
<comm>\n		{ BEGIN 0 ; }
<comm>.			{}

"/*"			{ BEGIN(comm1);}
<comm1>.		{}	
<comm1>\n		{}
<comm1>"*/"		{ BEGIN 0 ; }

"("|")"|"<"|">"|"&"|"*"|"^"|"/"|"["|"]"|\-|\+|"#"|","|";"|":"|"="|"{"|"}"		{return *yytext;}

{ID}			{ return tokID; }
<<EOF>>			{ return tokEOF; }
\n                      { }
.			{ }
%%



