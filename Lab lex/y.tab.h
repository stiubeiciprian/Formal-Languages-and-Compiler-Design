/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    CHAR = 259,
    STRING = 260,
    BOOL = 261,
    IF = 262,
    ELSE = 263,
    ELIF = 264,
    INPUT = 265,
    PRINT = 266,
    WHILE = 267,
    FOR = 268,
    ID = 269,
    CONST_INT = 270,
    CONST_BOOL = 271,
    CONST_CHAR = 272,
    CONST_STR = 273,
    ASSIGN = 274,
    NOTEQUAL = 275,
    LE = 276,
    GE = 277,
    EQUAL = 278,
    L = 279,
    G = 280,
    PLUS = 281,
    MINUS = 282,
    TIMES = 283,
    DIVIDE = 284,
    OR = 285,
    AND = 286,
    NOT = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define STRING 260
#define BOOL 261
#define IF 262
#define ELSE 263
#define ELIF 264
#define INPUT 265
#define PRINT 266
#define WHILE 267
#define FOR 268
#define ID 269
#define CONST_INT 270
#define CONST_BOOL 271
#define CONST_CHAR 272
#define CONST_STR 273
#define ASSIGN 274
#define NOTEQUAL 275
#define LE 276
#define GE 277
#define EQUAL 278
#define L 279
#define G 280
#define PLUS 281
#define MINUS 282
#define TIMES 283
#define DIVIDE 284
#define OR 285
#define AND 286
#define NOT 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "lang.y"

  	int l_val;
	char *p_val;

#line 126 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
