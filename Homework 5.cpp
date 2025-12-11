/*Make infix a posfix using the shunting yard algorithm*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Yýðýn için yapý ve fonksiyonlar
typedef struct {
    char items[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top < MAX - 1) s->items[++(s->top)] = c;
}

char pop(Stack *s) {
    if (s->top >= 0) return s->items[(s->top)--];
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0) return s->items[s->top];
    return '\0';
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// Operatör önceliði
int oncelik(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    Stack stack;
    stack.top = -1;
    int i = 0, k = 0;

    printf("Infix ifade girin: ");
    fgets(infix, sizeof(infix), stdin);

    while (infix[i] != '\0' && infix[i] != '\n') {
        char c = infix[i];

        if (isdigit(c)) {
            // Operand ise direkt postfix'e ekle
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(&stack, c);
        }
        else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            if (!isEmpty(&stack)) pop(&stack);  // '(' atýlýr
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!isEmpty(&stack) && oncelik(peek(&stack)) >= oncelik(c)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, c);
        }
        // boþluk veya baþka karakterler için iþlem yok
        i++;
    }

    // Yýðýnda kalanlarý çýkar
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';

    printf("Postfix ifade: %s\n", postfix);

    return 0;
}

