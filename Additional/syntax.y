%{
#include <stdio.h>
#include <ctype.h>
int yylex(), yyerror(char *s);
%}
%token ID
%left '+'
%left '*'
%%
expr:
      expr '+' expr
    | expr '*' expr
    | '(' expr ')'
    | ID
    ;
%%
int yylex(){
    char c;
    while ((c = getchar()) == ' ' || c == '\t');
    if (c == '\n')
        return 0;
    if (isalpha(c))
        return ID;
    return c;
}
int yyerror(char *s){
    return 0;
}
int main(){
    printf("Enter expression: ");
    if (yyparse() == 0)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
    return 0;
}