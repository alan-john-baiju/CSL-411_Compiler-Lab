%{
#include<stdio.h>
%}
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
NUMBER [0-9]+
WHITESPACE [ \t\n]+
OPERATOR [+\-*/=]
SPECIALSYMBOL [;,\(\)\{\}\[\]]
%%
"int" {printf("KEYWORD: int\n");}
"float" {printf("KEYWORD: float\n");}
"if" {printf("KEYWORD: if\n");}
"else" {printf("KEYWORD: else\n");}
"while" {printf("KEYWORD: while\n");}
"return" {printf("KEYWORD: return\n");}
{IDENTIFIER} {printf("IDENTIFIER: %s\n",yytext);}
{NUMBER} {printf("NUMBER: %s\n",yytext);}
{OPERATOR} {printf("OPERATOR: %s\n",yytext);}
{SPECIALSYMBOL} {printf("SPECIAL SYMBOL: %s\n",yytext);}
{WHITESPACE} {/*skip*/}
.    {printf("UNKNOWN CHARACTER: %s\n",yytext);}
%%
int main(){
    printf("Enter code: \n");
    yylex();
}
int yywrap(){
    return 1;
}