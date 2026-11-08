#include <stdio.h>
#include <string.h>
int main() {
    char icode[10][30];
    int i=0;
    printf("Enter 3AC code (end with exit):\n");
    do{
        scanf("%s", icode[i]);
    }while(strcmp(icode[i++],"exit")!=0);
    i=0;
    printf("\n8086 CODE:\n");
    while(strcmp(icode[i],"exit")!=0){
        char res[10], op1[10], op2[10];
        char op;
        sscanf(icode[i], "%[^=]=%[^+-*/]%c%s", res, op1, &op, op2);
        printf("\nMOV AX, %s", op1);
        if(op=='+') printf("\nADD AX, %s", op2);
        if(op=='-') printf("\nSUB AX, %s", op2);
        if(op=='*') { printf("\nMOV BX, %s", op2); printf("\nMUL BX"); }
        if(op=='/') { printf("\nMOV BX, %s", op2); printf("\nDIV BX"); }
        printf("\nMOV %s, AX", res);
        i++;
    }
    printf("\n");
    return 0;
}