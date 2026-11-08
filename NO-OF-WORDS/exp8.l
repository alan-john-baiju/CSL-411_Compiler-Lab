%{
    #include <stdio.h>
    int lc=0, sc=0, tc=0, wc=0, ch=0;
%}
%%
\n       { lc++; ch++; }
" "      { sc++; ch++; }
\t       { tc++; ch++; }
[^ \t\n]+ { wc++; ch+=yyleng; }
%%
int yywrap(){
    return 1;
}
int main(){
    printf("Enter a sentence:\n");
    yylex();
    printf("\nLines: %d\nSpaces: %d\nTabs: %d\nWords: %d\nCharacters: %d\n", lc, sc, tc, wc, ch);
    return 0;
}