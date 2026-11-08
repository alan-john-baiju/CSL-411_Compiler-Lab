%{
    #include<stdio.h>    
%}
%%
abc {printf("ABC");}
. | \n {printf("%s",yytext);}
%%
int main(){
    printf("Enter an input: \n");
    yylex();
    return 0;
}
int yywrap(void){
    return 1;
}