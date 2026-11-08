#include <stdio.h>
#include <string.h>
int main(){
    char s[50], operand[50][10], op[50], temp[10];
    int n = 0, m = 0, t = 1;
    int i, j;
    printf("Enter expression (e.g. a+b*c): ");
    scanf("%49s", s);
    for (i = 0; s[i]; i += 2){
        sprintf(operand[n++], "%c", s[i]);
        if (s[i + 1])
            op[m++] = s[i + 1];
    }
    for (i = 0; i < m; i++){
        if (op[i] == '*' || op[i] == '/'){
            sprintf(temp, "t%d", t++);
            printf("%s = %s %c %s\n",
                   temp, operand[i], op[i], operand[i + 1]);
            strcpy(operand[i], temp);
            for (j = i + 1; j < n - 1; j++)
                strcpy(operand[j], operand[j + 1]);
            for (j = i; j < m - 1; j++)
                op[j] = op[j + 1];
            n--; m--; i--;
        }
    }
    for (i = 0; i < m; i++){
        sprintf(temp, "t%d", t++);
        printf("%s = %s %c %s\n",
               temp, operand[i], op[i], operand[i + 1]);
        strcpy(operand[i], temp);
        for (j = i + 1; j < n - 1; j++)
            strcpy(operand[j], operand[j + 1]);
        for (j = i; j < m - 1; j++)
            op[j] = op[j + 1];
        n--; m--; i--;
    }
    printf("Result = %s\n", operand[0]);
    return 0;
}