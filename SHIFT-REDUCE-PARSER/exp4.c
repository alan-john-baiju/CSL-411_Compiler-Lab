#include <stdio.h>
#include <string.h>
char stack[100], input[100];
int top = 0, pos = 0;
int reduce(){
    /* id -> E */
    if(top >= 2 && stack[top-1] == 'i' && stack[top] == 'd'){
        stack[top-1] = 'E';
        top--;
        stack[top+1] = '\0';
        printf("%-15s %-15s id -> E\n", stack, input+pos);
        return 1;
    }
    /* (E) -> E */
    if(top >= 3 && stack[top-2] == '(' && stack[top-1] == 'E' && stack[top] == ')'){
        stack[top-2] = 'E';
        top -= 2;
        stack[top+1] = '\0';
        printf("%-15s %-15s (E) -> E\n", stack, input+pos);
        return 1;
    }
    /* E*E -> E */
    if(top >= 3 && stack[top-2] == 'E' && stack[top-1] == '*' && stack[top] == 'E'){
        stack[top-2] = 'E';
        top -= 2;
        stack[top+1] = '\0';
        printf("%-15s %-15s E*E -> E\n", stack, input+pos);
        return 1;
    }
    /* E+E -> E only if no * follows */
    if(top >= 3 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'E' && input[pos] != '*'){
        stack[top-2] = 'E';
        top -= 2;
        stack[top+1] = '\0';
        printf("%-15s %-15s E+E -> E\n", stack, input+pos);
        return 1;
    }
    return 0;
}
int main(){
    printf("Enter expression: ");
    scanf("%99s", input);
    strcat(input, "$");
    stack[top] = '$';
    stack[top+1] = '\0';
    printf("\nSTACK           INPUT           ACTION\n");
    printf("%-15s %-15s Start\n", stack, input+pos);
    while(input[pos] != '$'){
        if(input[pos] == 'i' && input[pos+1] == 'd'){
            stack[++top] = 'i';
            stack[++top] = 'd';
            pos += 2;
        }
        else{
            stack[++top] = input[pos++];
        }
        stack[top+1] = '\0';
        printf("%-15s %-15s Shift\n", stack, input+pos);
        while(reduce());
    }
    while(reduce());
    if(strcmp(stack, "$E") == 0)
        printf("\nValid Expression\n");
    else
        printf("\nInvalid Expression\n");
    return 0;
}