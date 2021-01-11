%{
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1

#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_CHAR 3
#define TYPE_STRING 4

double stack[20];
int sp;

void push(double x)
{ stack[sp++]=x; }

double pop()
{ return stack[--sp]; }

%}

%union {
  	int l_val;
	char *p_val;
}

%token INT
%token CHAR
%token STRING
%token BOOL
%token IF
%token ELSE
%token ELIF
%token INPUT
%token PRINT
%token WHILE
%token FOR


%token ID
%token <p_val> CONST_INT
%token <p_val> CONST_BOOL
%token <p_val> CONST_CHAR
%token CONST_STR


%token ASSIGN
%token NOTEQUAL
%token LE
%token GE
%token EQUAL
%token L
%token G

%left PLUS MINUS
%left TIMES DIVIDE
%left OR
%left AND
%left NOT

%%
program:    statementList
		;
statementList:  statement
        | statement statementList
		;
statement:  simpleStatement
        | structStatement
		;
compoundStatement: statement | statement compoundStatement
        ;
simpleStatement:    variableDeclarationStatement
        | assignmentStatement
        | printStatement
        | readStatement
		;
variableDeclarationStatement:   type ID 
        | type ID EQUAL expression
		;
assignmentStatement:    ID EQUAL expression
        | ID '[' CONST_INT ']' EQUAL expression
		;
printStatement: PRINT '(' ID ')'
        | PRINT '(' constant ')'
        | PRINT '(' expression ')'
		;
readStatement:  INPUT '(' CONST_STR ')'
		;
basicType:  INT
        | CHAR
        | STRING
        | BOOL
		;
arrayType:  basicType '[' CONST_INT ']'
		;
type:   basicType
		| arrayType
		;
expression: arithmeticExpression
        | logicExpression
        | relationalExpression
        ;
condition:  logicExpression
        | relationalExpression
        | ID
        | constant
        | NOT logicExpression
        | NOT relationalExpression
        | NOT ID
        | NOT constant
		;
arithmeticExpression:   arithmeticExpression PLUS term
        | arithmeticExpression MINUS term
        | term
		;
term:   term TIMES factor
        | term DIVIDE factor
        | factor
		;
factor: '(' arithmeticExpression ')'
        | ID
        | CONST_INT
		;
logicExpression:    expression OR expression
        | expression AND expression
		;
relationalExpression:   arithmeticExpression relation arithmeticExpression
        ;
relation: EQUAL
        | NOTEQUAL
        | LE
        | GE
        | L
        | G
        ;
constant: CONST_INT
        | CONST_CHAR
        | CONST_STR
        ;
structStatement:    compoundStatement
        | ifStatement
        | whileStatement
        | forStatement
		;
ifStatement:	IF condition ':' statement
		| IF condition ':' statement ELSE ':' statement
		| IF condition ':' statement ELIF statement
		;
whileStatement:	    WHILE condition ':' statement
		;
forStatement:	FOR variableDeclarationStatement ',' condition ',' assignmentStatement ':' statement
		;

%%

yyerror(char *s)
{
  printf("%s\n", s);
}

extern FILE *yyin;

main(int argc, char **argv)
{
  if(argc>1) yyin = fopen(argv[1], "r");
  if((argc>2)&&(!strcmp(argv[2],"-d"))) yydebug = 1;
  if(!yyparse()) fprintf(stderr,"\tO.K.\n");
}

