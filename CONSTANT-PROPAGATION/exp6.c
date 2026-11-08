#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main() {
    char op[10][5], a[10][5], b[10][5], res[10][5], temp[5];
    int i, n, j, x, y, z, flag[10] = {0};
    printf("Enter number of expressions: ");
    scanf("%d", &n);
    printf("Enter expressions (op op1 op2 result):\n");
    for(i = 0; i < n; i++)
        scanf("%s%s%s%s", op[i], a[i], b[i], res[i]);
    for(i = 0; i < n; i++) {
        if((isdigit(a[i][0]) && isdigit(b[i][0])) || strcmp(op[i], "=") == 0) {
            x = atoi(a[i]);
            y = atoi(b[i]);
            switch(op[i][0]) {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': 
                    if(y == 0) continue;
                    z = x / y; 
                    break;
                case '=': z = x; break;
                default: continue;
            }
            sprintf(temp, "%d", z);
            flag[i] = 1;
            for(j = i + 1; j < n; j++) {
                if(strcmp(res[i], a[j]) == 0)
                    strcpy(a[j], temp);
                if(strcmp(res[i], b[j]) == 0)
                    strcpy(b[j], temp);
            }
        }
    }
    printf("\nOptimized code:\n");
    for(i = 0; i < n; i++)
        if(!flag[i])
            printf("%s %s %s %s\n", op[i], a[i], b[i], res[i]);
    return 0;
}