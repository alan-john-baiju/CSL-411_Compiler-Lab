#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char c){
    stack[++top] = c;
}
void pop(){
    top--;
}
int value(char x){
    switch(x){
        case 'i': return 0;
        case '+': return 1;
        case '*': return 2;
        case '$': return 3;
        case '(': return 4;
        case ')': return 5;
    }
    return 0;
}
char Matrix[][6] = {
    {' ', '>', '>', '>', ' ', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '>', '<', '>', '<', '>'},
    {'<', '<', '<', ' ', '<', ' '},
    {'<', '<', '<', ' ', '<', '='},
    {' ', '>', '>', '>', ' ', '>'}
};
void main(){
    int i, j = 0, balance = 0, need = 1;
    char a, b, c, input[100], temp[100];
    printf("Enter the string: ");
    scanf("%s", input);
    /* Convert id to i */
    for(i = 0; i < strlen(input); i++){
        if(input[i] == 'i' && input[i+1] == 'd'){
            temp[j++] = 'i';
            i++;
        }
        else if(input[i] == '+' || input[i] == '*' ||
                input[i] == '(' || input[i] == ')')
            temp[j++] = input[i];
        else{
            printf("The string is not accepted.\n");
            return;
        }
    }
    temp[j] = '$';
    temp[j+1] = '\0';
    /* Check valid expression */
    for(i = 0; i < j; i++){
        if(need){
            if(temp[i] == 'i')
                need = 0;
            else if(temp[i] == '(')
                balance++;
            else
                goto invalid;
        }
        else{
            if(temp[i] == '+' || temp[i] == '*')
                need = 1;
            else if(temp[i] == ')' && balance > 0)
                balance--;
            else
                goto invalid;
        }
    }
    if(need || balance != 0)
        goto invalid;
    /* Operator precedence parsing */
    stack[++top] = '$';
    i = 1;
    while(top != -1){
        a = stack[top];
        b = temp[i];
        c = Matrix[value(a)][value(b)];
        if(a == '$' && b == '$'){
            printf("The string is accepted!\n");
            return;
        }
        if(c == '<' || c == '='){
            push(c);
            push(b);
            i++;
        }
        else if(c == '>'){
            while(stack[top] != '<')
                pop();
            pop();
        }
        else
            goto invalid;
    }
invalid:
    printf("The string is not accepted.\n");
}