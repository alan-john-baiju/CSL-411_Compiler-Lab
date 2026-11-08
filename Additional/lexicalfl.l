%{
#include <stdio.h>
%}
%%
"int"|"float"|"char"|"if"|"else"|"while"|"return" { fprintf(yyout, "KEYWORD: %s\n", yytext); }
[0-9]+ { fprintf(yyout, "NUMBER: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { fprintf(yyout, "IDENTIFIER: %s\n", yytext); }
[+\-*/=] { fprintf(yyout, "OPERATOR: %s\n", yytext); }
[(){}\[\];,] { fprintf(yyout, "SYMBOL: %s\n", yytext);}
[ \t\n]+     ;
. { fprintf(yyout, "UNKNOWN: %s\n", yytext); }
%%
int main(){
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    if (yyin == NULL || yyout == NULL) {
        printf("File error\n");
        return 1;
    }
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}
int yywrap(){
    return 1;
}