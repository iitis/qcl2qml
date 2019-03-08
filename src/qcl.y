%{
#include "qcl.hh"
#include "lex.qcl.c"
#include <string>



using namespace std;

#define YYPARSE_PARAM *mainSymbol /// parameter for yyparse


int yyerror(char * s) { return 0;}

%}

%name-prefix="qcl"
%defines 
%debug 


%union{
	Symbol * symbol;
	Identifier * ident;
	Expression * expression;
    Def * definition;
	Value * value;
	SymbolType stype;
	string * STRING;
	int INT;
 	double REAL; 
}

%type <ident> identifier identifier1 identifier2
%type <symbol> top_symbol stmt stmt1 def error block block1 body 
%type <expression>  expr1 expr 
%type <definition> var_def arg_def1 arg_def arg_list const_def
%type <value> const
//%type <opt> option
%type <stype> type



%token tokAND
%token tokBOOLEAN
%token tokBOTHARROW
%token tokCOMPLEX
%token <REAL> tokCOMPLEX_COORD
%token tokCONST 
%token <INT> tokCONSTI
%token tokCONSTR
%token tokDUMP
%token tokELSE
%token tokEOF
%token tokEOL
%token tokEQ
%token tokEXIT 
%token tokEXTERN
%token tokFALSE
%token tokFOR 
%token tokGORE
%token tokID
%token tokIF
%token tokINPUT 
%token tokINT 
%token tokLEFTARROW
%token tokLETTER
%token tokLIST
%token tokLOAD
%token tokLORE
%token tokMEASURE
%token tokMOD
%token tokMULTDOT
%token tokNEQ
%token tokNOT
%token tokOPERATOR 
%token tokOR
%token tokPRINT
%token tokPROCEDURE
%token tokQUCONST
%token tokQUFUNCT
%token tokQUREG
%token tokQUSCRATCH  
%token tokQUVOID
%token tokREAL
%token tokRESET 
%token tokRETURN
%token tokRIGHTARROW 
%token tokSAVE
%token tokSET
%token tokSHELL
%token tokSTEP
%token tokSTRING
%token <STRING> tokSTRINGCONST
%token tokTO
%token tokTRUE 
%token tokUNTIL
%token tokWHILE
%token tokXOR  


%nonassoc tokEQ tokNEQ tokLORE tokGORE '<' '>'
%left tokOR tokXOR
%left tokAND
%left tokNOT
%left '&'
%left '/' '*'
%left '^'		/* "All binary operators are left assocsiative." */
%left '#'
%right UMINUS
%%



qcl_input: top_symbol tokEOF		{ *mainSymbol = $1; return 1;}
;

top_symbol: stmt			{ $$ = $1; }		
	| def				{ $$ = $1; }
	| stmt top_symbol		{ $1->addNext($2); $$ = $1; }
	| def top_symbol		{ $1->addNext($2); $$ = $1; }
	| error '\n'			{ $$ = new Error(); }
	| error tokEOF			{ $$ = new Error(); }
;


/* A.1 EXPRESSIONS */



const :	'(' const ',' const ')'				{ $$ = new Complex($2,$4); }
	| '-' const					{ $2->minus(); $$=$2; }
	| tokCOMPLEX_COORD				{ $$ = new Real(yylval.REAL); }
	| tokCONSTI					{ $$ = new Integer(yylval.INT); }
	| tokTRUE					{ $$ = new Boolean(true); }
	| tokFALSE					{ $$ = new Boolean(false); }
	| tokSTRINGCONST				{ $$ = new String(*(yylval.STRING)); }
	| '(' error ')'					{ $$ = new ErrorVal(); }
	| error						{ $$ = new ErrorVal(); }
;


	
expr : const						{ $$ = new Constant($1); }
	| identifier '[' expr ':' expr ']'		{ $$ = new IdQExpression($1,$3,$5,FROMTO); }
	| identifier '[' expr tokMULTDOT expr ']'	{ $$ = new IdQExpression($1,$3,$5,FROMTO); }
	| identifier '[' expr '\\' expr ']'		{ $$ = new IdQExpression($1,$3,$5,FROMN); }
	| identifier '[' expr ']'			{ $$ = new IdQExpression($1,$3); }
	| identifier					{ $$ = new IdExpression($1); }
	| identifier '(' expr1 ')'			{ $$ = new FunctCall( $1, $3 ); }
	| '(' expr ')'					{ $$ = $2; }
	| '#' expr					{ $$ = new RegSizeExpression($2); }
	| expr '^' expr					{ $$ = new PowExpression($1,$3); }
	| '-' expr		%prec UMINUS		{ $$ = new NegExpression($2); }
	| expr '*' expr					{ $$ = new MultExpression($1,$3); }
	| expr '/' expr					{ $$ = new DivExpression($1,$3); }
	| expr tokMOD expr				{ $$ = new ModExpression($1,$3); }
	| expr '+' expr					{ $$ = new AddExpression($1,$3); }
	| expr '-' expr					{ $$ = new SubExpression($1,$3); }
	| expr '&' expr					{ $$ = new ConExpression($1,$3); }
	| expr tokEQ expr				{ $$ = new IsEqExpression($1,$3); }
	| expr tokNEQ  expr				{ $$ = new IsNEqExpression($1,$3); }
	| expr '<' expr					{ $$ = new IsLessExpression($1,$3); }
	| expr tokLORE expr				{ $$ = new IsLessOrEqExpression($1,$3); }
	| expr '>' expr					{ $$ = new IsGrExpression($1,$3); }
	| expr tokGORE expr				{ $$ = new IsGrOrEqExpression($1,$3); }
	| tokNOT expr					{ $$ = new NotExpression($2); }
	| expr tokAND expr				{ $$ = new AndExpression($1,$3); }
	| expr tokOR expr				{ $$ = new OrExpression($1,$3); }
	| expr tokXOR expr				{ $$ = new XorExpression($1,$3); }
;

expr1 :							{ $$ = 0; }
	| expr						{ $$ = $1;}
	| expr ',' expr1				{ $1->addNext($3); $$=$1; }
;


identifier: tokID					{ $$ = new Identifier(::qcltext);}
;

identifier1:						{ $$ = 0; }
	| identifier					{ $$ = $1; }
	| identifier ',' identifier2			{ $1->addNext($3); $$=$1; }
;

/* A.2. Statements */

stmt : '!' identifier '(' expr1 ')' ';'			{ $$ = new RoutineCall($2,$4,true) ; }
	| identifier '(' expr1 ')' ';'			{  $$ = new RoutineCall($1,$3) ; }
	| identifier '=' expr ';'			{ $$ = new VarAssig($1,$3); }	
	| expr tokLEFTARROW expr ';'			{ $$ = new FanoutOperator($3,$1) ; }
	| expr tokRIGHTARROW expr ';'			{ $$ = new FanoutOperator($1,$3) ; }
	| expr tokBOTHARROW expr ';'			{ $$ = new SwapOperator($1,$3) ; }
	| tokFOR identifier '=' expr tokTO expr tokSTEP expr block	
							{ $$ = new ForStmt($2,$4,$6,$9,$8) ; }
	| tokFOR identifier '=' expr tokTO expr block	{ $$ = new ForStmt($2,$4,$6,$7); }
	| tokWHILE expr block				{ $$ = new WhileStmt($2,$3) ; }
	| block tokUNTIL expr ';'			{ $$ = new UntilStmt($3,$1) ; }
	| tokIF expr block tokELSE block		{ $$ = new IfStmt($2,$3,$5) ; }
	| tokIF expr block				{ $$ = new IfStmt($2,$3); }
	| tokRETURN expr ';'				{ $$ = new ReturnStmt($2) ; }
	| tokINPUT identifier ';'			{ $$ = new Input($2) ; }
	| tokINPUT expr ',' identifier ';'		{ $$ = new Input($4,$2); }
	| tokPRINT expr1 ';'				{ $$ = new PrintStmt($2); }
	| tokEXIT expr ';'				{ $$ = new Exit($2) ; }
	| tokEXIT ';'					{ $$ = new Exit() ; }
	| tokMEASURE expr ';'				{ $$ = new Measure($2) ; }
	| tokMEASURE expr ',' identifier ';'		{ $$ = new Measure($2,$4) ; }
	| tokRESET ';'					{ $$ = new Reset() ; }
	| tokDUMP ';'					{ $$ = new Dump() ; }
	| tokDUMP expr ';'				{ $$ = new Dump($2) ; }
	| tokLOAD ';'					{ $$ = new Load() ; }
	| tokLOAD expr ';'				{ $$ = new Load($2) ; }
	| tokSAVE ';'					{ $$ = new Save() ; }
	| tokSAVE expr ';'				{ $$ = new Save($2) ; }
	| tokSHELL ';'					{ $$ = new Shell() ; }
/*	| tokSET option ',' expr ';'			{ $$ = 0 ; }*/
/*	| tokSET option ';'				{ $$ = 0 ; }*/
	| stmt ";"					{ $$ = $1; } 
;
stmt1:							{ $$ = 0; }
	| stmt						{ $$ = $1; }
	| stmt stmt1					{ $1->addNext($2); $$ = $1; }
;

/* A.3. Definitions */

type: tokBOOLEAN				{ $$ = BOOLEAN ; } 
	| tokINT				{ $$ = INTEGER; }
	| tokREAL				{ $$ = REAL; }
	| tokCOMPLEX				{ $$ = COMPLEX; }
	| tokSTRING				{ $$ = STRING; }
	| tokQUREG				{ $$ = QUREG; }
	| tokQUVOID				{ $$ = QUVOID; }
	| tokQUCONST				{ $$ = QUCONST; }
	| tokQUSCRATCH				{ $$ = QUSCRATCH; }
;

const_def: tokCONST identifier '=' expr ';'	{ $$ = new Def($2,CONST,$4);}

var_def: type identifier '[' expr ']' ';'	{ $$ = new Defq($2,$1,$4); }
	| type identifier '=' expr ';'		{ $$ = new Def($2,$1,$4); }
	| type identifier ';'			{ $$ = new Def($2,$1); }
;

arg_def: type identifier			{ $$ = new Def($2,$1); }
;

arg_def1: arg_def ',' arg_def1			{ $1->addNext($3); $$=$1;}
	| arg_def				{ $$ = $1;}
	|					{ $$ = 0;}
;

arg_list: '(' arg_def1 ')'			{ $$ = $2; }
	| '(' error ')'				{ $$ = 0;}
;

body: '{' top_symbol '}'	{ $$=$2; }
	| '{' '}'		{ $$=0;}
;


def: const_def						{ $$ = $1; }
	| var_def					{ $$ = $1; }
	| type identifier arg_list body			{ $$ = new FunctDef($2,$1,$3,$4); }
	| tokPROCEDURE identifier arg_list body		{ $$ = new ProcDef($2,$3,$4);}
	| tokOPERATOR  identifier arg_list body		{ $$ = new OperDef($2,$3,$4);}
	| tokQUFUNCT  identifier arg_list body		{ $$ = new QufuncDef($2,$3,$4); }
	| tokEXTERN tokOPERATOR  identifier arg_list	{ $$ = new ExOperDef($3,$4); }
	| tokEXTERN tokQUFUNCT  identifier arg_list	{ $$ = new ExQufuncDef($3,$4); }
;

block: '{' block1 '}'					{ $$ = $2; }
;

block1: stmt						{ $$ = $1; }
	| stmt block1					{ $1->addNext($2); $$=$1; }
;


option: tokLETTER
	| tokLETTER option1
;

option1: tokLETTER
	| '-'
;

identifier2:
;

%%





