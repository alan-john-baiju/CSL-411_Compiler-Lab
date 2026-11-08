%{
#include <stdio.h>
int yylex();
int yyerror();
%}
%token LETTER DIGIT
%%
start:
      LETTER rest '\n' { printf("Valid Identifier\n"); return 0;}
    | '_' rest '\n'    { printf("Valid Identifier\n"); return 0;}
;
rest:
      /* empty */
    | rest LETTER
    | rest DIGIT
    | rest '_'
;
%%
int yylex(){
    char c = getchar();
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        return LETTER;
    if (c >= '0' && c <= '9')
        return DIGIT;
    return c;
}
int yyerror(){
    printf("Invalid Identifier\n");
    return 0;
}
int main(){
    printf("Enter identifier: ");
    yyparse();
}