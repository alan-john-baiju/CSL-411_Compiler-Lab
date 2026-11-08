%{
#include <stdio.h>
#include <ctype.h>
int yylex();
void yyerror(char *s);
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S : E '\n' { printf("Result = %d\n", $1); return 0;};
E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | NUM     { $$ = $1; };
%%
int yylex(){
    int c, num = 0;
    c = getchar();
    if (isdigit(c)){
        while (isdigit(c)){
            num = num * 10 + (c - '0');
            c = getchar();
        }
        ungetc(c, stdin);
        yylval = num;
        return NUM;
    }
    return c;
}
void yyerror(char *s){
    printf("Invalid Expression\n");
}
int main(){
    printf("Enter Expression: ");
    yyparse();
}