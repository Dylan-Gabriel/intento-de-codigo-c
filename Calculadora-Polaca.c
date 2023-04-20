/*Claro, ¡sin problema! Aquí te dejo la implementación que admite espacios para separar los elementos de la expresión en notación polaca inversa:

c*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OPERATOR_ADDITION '+'
#define OPERATOR_SUBTRACTION '-'
#define OPERATOR_MULTIPLICATION '*'
#define OPERATOR_DIVISION '/'

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int pop(Node** head) {
    if (*head == NULL) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    int data = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

int isEmpty(Node* head) {
    return (head == NULL);
}

int peek(Node* head) {
    if (isEmpty(head)) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return head->data;
}

int isOperator(char c) {
    return (c == OPERATOR_ADDITION || c == OPERATOR_SUBTRACTION || c == OPERATOR_MULTIPLICATION || c == OPERATOR_DIVISION);
}

int evaluatePostfix(char* postfix) {
    Node* stack = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            int operand = c - '0';
            while (isdigit(postfix[i+1])) {
                operand = operand*10 + (postfix[++i] - '0');
            }
            push(&stack, operand);
        }
        else if (isOperator(c)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch(c) {
                case OPERATOR_ADDITION:
                    push(&stack, operand1 + operand2);
                    printf("%d + %d = %d\n", operand1, operand2, operand1 + operand2);
                    break;
                case OPERATOR_SUBTRACTION:
                    push(&stack, operand1 - operand2);
                    printf("%d - %d = %d\n", operand1, operand2, operand1 - operand2);
                    break;
                case OPERATOR_MULTIPLICATION:
                    push(&stack, operand1 * operand2);
                    printf("%d * %d = %d\n", operand1, operand2, operand1 * operand2);
                    break;
                case OPERATOR_DIVISION:
                    push(&stack, operand1 / operand2);
                    printf("%d / %d = %d\n", operand1, operand2, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char input[100];
    printf("Introduce la expresión en notación polaca inversa (con espacios): ");
    fgets(input, 100, stdin);

    int result = evaluatePostfix(input);

    printf("Resultado: %d\n", result);

    return 0;
}


/*En este código, se ha modificado la función `evaluatePostfix` para que pueda procesar una cadena de entrada que contenga espacios. Si el carácter actual es un dígito, se construye el operando escaneando la cadena hasta que se encuentra un carácter que no es dígito. Esto asegura que se capturen operandos con más de un dígito.

También hemos utilizado `fgets` en lugar de `scanf` para leer la cadena de entrada, ya que esto permite leer cadenas con espacios.

Espero que esto te sea útil. Que tengas un buen día.*/