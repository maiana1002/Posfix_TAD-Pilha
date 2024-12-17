#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef struct {
int top;
int items[MAX_SIZE];
} Stack;


void initialize(Stack *s) {
s->top = -1;
}

int isEmpty(Stack *s) {
return s->top == -1;
}

int isFull(Stack *s) {
return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int value) {
if (isFull(s)) {
printf("Stack Overflow\n");
exit(EXIT_FAILURE);
} else {
s->items[++s->top] = value;
}
}

int pop(Stack *s) {
if (isEmpty(s)) {
printf("Stack Underflow\n");
exit(EXIT_FAILURE);
} else {
return s->items[s->top--];
}
}

// Posfix
int evaluatePostfix(char *exp) {
Stack stack;
initialize(&stack);

for (int i = 0; exp[i] != '\0'; i++) {
if (isdigit(exp[i])) {
push(&stack, exp[i] - '0');
} else {
int operand2 = pop(&stack);
int operand1 = pop(&stack);

switch (exp[i]) {
case '+':
push(&stack, operand1 + operand2);
break;
case '-':
push(&stack, operand1 - operand2);
break;
case '*':
push(&stack, operand1 * operand2);
break;
case '/':
push(&stack, operand1 / operand2);
break;
}
}
}

return pop(&stack);
}

int main() {
char exp1[] = "23+";
char exp2[] = "235*+";
char exp3[] = "23+5*";

printf("Resultado: %s: %d\n", exp1, evaluatePostfix(exp1));
printf("Resultado: %s: %d\n", exp2, evaluatePostfix(exp2));
printf("Resultado: %s: %d\n", exp3, evaluatePostfix(exp3));

  return 0;
}
