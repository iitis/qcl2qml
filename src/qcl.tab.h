/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tokAND = 258,
     tokBOOLEAN = 259,
     tokBOTHARROW = 260,
     tokCOMPLEX = 261,
     tokCOMPLEX_COORD = 262,
     tokCONST = 263,
     tokCONSTI = 264,
     tokCONSTR = 265,
     tokDUMP = 266,
     tokELSE = 267,
     tokEOF = 268,
     tokEOL = 269,
     tokEQ = 270,
     tokEXIT = 271,
     tokEXTERN = 272,
     tokFALSE = 273,
     tokFOR = 274,
     tokGORE = 275,
     tokID = 276,
     tokIF = 277,
     tokINPUT = 278,
     tokINT = 279,
     tokLEFTARROW = 280,
     tokLETTER = 281,
     tokLIST = 282,
     tokLOAD = 283,
     tokLORE = 284,
     tokMEASURE = 285,
     tokMOD = 286,
     tokMULTDOT = 287,
     tokNEQ = 288,
     tokNOT = 289,
     tokOPERATOR = 290,
     tokOR = 291,
     tokPRINT = 292,
     tokPROCEDURE = 293,
     tokQUCONST = 294,
     tokQUFUNCT = 295,
     tokQUREG = 296,
     tokQUSCRATCH = 297,
     tokQUVOID = 298,
     tokREAL = 299,
     tokRESET = 300,
     tokRETURN = 301,
     tokRIGHTARROW = 302,
     tokSAVE = 303,
     tokSET = 304,
     tokSHELL = 305,
     tokSTEP = 306,
     tokSTRING = 307,
     tokSTRINGCONST = 308,
     tokTO = 309,
     tokTRUE = 310,
     tokUNTIL = 311,
     tokWHILE = 312,
     tokXOR = 313,
     UMINUS = 314
   };
#endif
/* Tokens.  */
#define tokAND 258
#define tokBOOLEAN 259
#define tokBOTHARROW 260
#define tokCOMPLEX 261
#define tokCOMPLEX_COORD 262
#define tokCONST 263
#define tokCONSTI 264
#define tokCONSTR 265
#define tokDUMP 266
#define tokELSE 267
#define tokEOF 268
#define tokEOL 269
#define tokEQ 270
#define tokEXIT 271
#define tokEXTERN 272
#define tokFALSE 273
#define tokFOR 274
#define tokGORE 275
#define tokID 276
#define tokIF 277
#define tokINPUT 278
#define tokINT 279
#define tokLEFTARROW 280
#define tokLETTER 281
#define tokLIST 282
#define tokLOAD 283
#define tokLORE 284
#define tokMEASURE 285
#define tokMOD 286
#define tokMULTDOT 287
#define tokNEQ 288
#define tokNOT 289
#define tokOPERATOR 290
#define tokOR 291
#define tokPRINT 292
#define tokPROCEDURE 293
#define tokQUCONST 294
#define tokQUFUNCT 295
#define tokQUREG 296
#define tokQUSCRATCH 297
#define tokQUVOID 298
#define tokREAL 299
#define tokRESET 300
#define tokRETURN 301
#define tokRIGHTARROW 302
#define tokSAVE 303
#define tokSET 304
#define tokSHELL 305
#define tokSTEP 306
#define tokSTRING 307
#define tokSTRINGCONST 308
#define tokTO 309
#define tokTRUE 310
#define tokUNTIL 311
#define tokWHILE 312
#define tokXOR 313
#define UMINUS 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "qcl.y"
{
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
/* Line 1529 of yacc.c.  */
#line 179 "qcl.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE qcllval;

