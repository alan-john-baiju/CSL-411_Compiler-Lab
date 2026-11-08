
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100];
int pos = 0, count = 0;
void expr(char result[]);
char op[50][15], arg1[50][15], arg2[50][15];

/* Generate a triple */
void emit(char operator[], char a1[], char a2[], char result[]) {
    strcpy(op[count], operator);
    strcpy(arg1[count], a1);
    strcpy(arg2[count], a2);

    sprintf(result, "(%d)", count);
    count++;
}

/* Read an operand or parenthesized expr */
void primary(char result[]) {
    if (s[pos] == '(') {
        pos++;
        expr(result);
        pos++;
    }
    else {
        result[0] = s[pos++];
        result[1] = '\0';
    }
}

/* Handle unary minus */
void unary(char result[]) {
    char a[15];

    if (s[pos] == '-') {
        pos++;
        unary(a);
        emit("unaryminus", a, "", result);
    }
    else {
        primary(result);
    }
}

/* Handle multiplication */
void term(char result[]) {
    char a[15], b[15];

    unary(result);

    while (s[pos] == '*') {
        pos++;
        strcpy(a, result);
        unary(b);
        emit("*", a, b, result);
    }
}

/* Handle addition */
void expr(char result[]) {
    char a[15], b[15];

    term(result);

    while (s[pos] == '+') {
        pos++;
        strcpy(a, result);
        term(b);
        emit("+", a, b, result);
    }
}

int main() {
    char lhs[15], rhs[15], result[15];
    int i;

    printf("Enter expr: ");
    scanf("%99s", s);

    /* Read assignment variable */
    lhs[0] = s[pos++];
    lhs[1] = '\0';

    pos++;  /* Skip '=' */

    /* Generate expr triples */
    expr(rhs);

    /* Generate assignment triple */
    emit("=", lhs, rhs, result);

    /* Display Indirect Triple */
    printf("\nIndirect Triple\n");
    printf("No\tOp\t\tArg1\tArg2\n");

    for (i = 0; i < count; i++) {
        printf("(%d)\t%-12s\t%-8s%s\n",
               i, op[i], arg1[i], arg2[i]);
    }

    /* Display Statement Pointer Table */
    printf("\nPointer\tStatement\n");

    for (i = 0; i < count; i++) {
        printf("(%d)\t(%d)\n", i, i);
    }

    return 0;
}
