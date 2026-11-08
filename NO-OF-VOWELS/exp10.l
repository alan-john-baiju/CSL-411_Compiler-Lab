%{
#include<stdio.h>
int vowels = 0, consonants = 0;
%}
%%
[aAeEiIoOuU]          { vowels++; }
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]   { consonants++; }
[ \t\n]              { }
.                    { }
%%
int main(){
    printf("Enter a string:\n");
    yylex();
    printf("\nNumber of vowels     : %d\n", vowels);
    printf("Number of consonants : %d\n", consonants);
    return 0;
}
int yywrap(){
    return 1;
}