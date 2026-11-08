#include <stdio.h>
void print(int a[], int n){
    int i, first = 1;
    printf("{");
    for (i = 0; i < n; i++){
        if (a[i] == 1){
            if (first == 0)
                printf(",");
            printf("q%d", i);
            first = 0;
        }
    }
    if (first == 1)
        printf(" ");
    printf("}");
}
int main(){
    int n, m, i, j, k, x, t, found, count = 1, front = 0;
    int nfa[10][2][10] = {0}, dfa[100][2], states[100][10] = {0}, next[10];
    char sym[2];
    printf("Number of NFA states: ");
    scanf("%d", &n);
    printf("Number of symbols: ");
    scanf("%d", &m);
    printf("Enter symbols: ");
    for (i = 0; i < m; i++)
        scanf(" %c", &sym[i]);
    /* Read NFA transitions */
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("\nTransitions from q%d using %c\n", i, sym[j]);
            printf("Number of transitions: ");
            scanf("%d", &t);
            printf("Destination states: ");
            for (k = 0; k < t; k++){
                scanf("%d", &x);
                nfa[i][j][x] = 1;
            }
        }
    }
    /* Initial DFA state = {q0} */
    states[0][0] = 1;
    /* Convert NFA to DFA */
    while (front < count){
        for (j = 0; j < m; j++){
            // Checking Next state for the current DFA state
            for (i = 0; i < n; i++)
                next[i] = 0;
            for (i = 0; i < n; i++){
                if (states[front][i] == 1){
                    for (k = 0; k < n; k++){
                        if (nfa[i][j][k] == 1)
                            next[k] = 1;
                    }
                }
            }
            // Check if the next state already exists in the states array
            found = -1;
            for (x = 0; x < count; x++){
                for (i = 0; i < n; i++){
                    if (states[x][i] != next[i])
                        break;
                }
                if (i == n){
                    found = x;
                    break;
                }
            }
            // If the next state is new, add it to the states array
            if (found == -1){
                found = count;
                for (i = 0; i < n; i++)
                    states[count][i] = next[i];
                count++;
            }
            dfa[front][j] = found;
        }
        front++;
    }
    /* Print DFA */
    printf("\nEquivalent DFA\n\n");
    printf("State\t");
    for (i = 0; i < m; i++)
        printf("%c\t", sym[i]);
    printf("\n");
    for (i = 0; i < count; i++){
        print(states[i], n);
        printf("\t");
        for (j = 0; j < m; j++){
            print(states[dfa[i][j]], n);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}