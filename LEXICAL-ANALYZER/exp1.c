#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    FILE *in=fopen("input.txt","r"),*out=fopen("output.txt","w");
    char ch,s[30],keyword[][10]={"int","main","if","return","else","while","printf"};
    int i,j,l=1,t=1,flag;
    fprintf(out,"Tokenized Code:\nLine no\tToken no\tToken\t\t Lexeme\n");
    while((ch=fgetc(in))!=EOF){
        if(ch=='/'){
            char c=fgetc(in);
            if(c=='/'){
                while((ch=fgetc(in))!='\n'&&ch!=EOF);
                l++;
                continue;
            }
            if(c=='*'){
                char p=0;
                while((ch=fgetc(in))!=EOF){
                    if(ch=='\n')
                        l++;
                    if(p=='*'&&ch=='/')
                        break;
                    p=ch;
                }
                continue;
            }
            ungetc(c,in);
        }
        if(strchr("+-*/",ch))
            fprintf(out,"%7d\t%7d\t   Operator\t\t%7c\n",l,t++,ch);
        else if(strchr("(){}=;,[]",ch))
            fprintf(out,"%7d\t%7d\t   Special Symbol\t%7c\n",l,t++,ch);
        else if(isdigit(ch))
            fprintf(out,"%7d\t%7d\t   Digit\t\t%7c\n",l,t++,ch);
        else if(isalpha(ch)){
            for(i=0;isalnum(ch);ch=fgetc(in))
                s[i++]=ch;
            s[i]='\0';
            ungetc(ch,in);
            flag=0;
            for(j=0;j<5;j++){
                if(strcmp(s,keyword[j])==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                fprintf(out,"%7d\t%7d\t   Keyword\t\t%7s\n",l,t++,s);
            else
                fprintf(out,"%7d\t%7d\t   Identifier\t\t%7s\n",l,t++,s);
        }
        else if(ch=='\n')
            l++;
    }
    printf("Tokenization completed.\n");
    fclose(in);
    fclose(out);
}