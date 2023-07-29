#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

// Função para criar um novo nó
NO* createNode(char data) {
    NO* newNode = malloc(sizeof(NO));
    newNode->chave = data;
    newNode->esquerda = NULL;
    newNode->direita = NULL;
    return newNode;
}

// Função para criar uma nova pilha
PILHA* createStack() {
    PILHA* pilha = malloc(sizeof(PILHA));
    pilha->topo = NULL;
    return pilha;
}

// Função para verificar se a pilha está vazia
int isStackEmpty(PILHA* pilha) {
    return pilha->topo == NULL;
}

// Função para empilhar um elemento na pilha
void push(PILHA* pilha, NO* chave) {
    NoPilha* newNode = malloc(sizeof(NoPilha));
    newNode->chave = chave;
    newNode->proximo = pilha->topo;
    pilha->topo = newNode;
}

// Função para desempilhar um elemento da pilha
NO* pop(PILHA* pilha) {
    if (isStackEmpty(pilha)) {
        return NULL;
    }

    NO* chave = pilha->topo->chave;
    NoPilha* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return chave;
}

// Função para obter o topo da pilha sem desempilhar
NO* peek(PILHA* pilha) {
    if (isStackEmpty(pilha)) {
        return NULL;
    }
    return pilha->topo->chave;
}

// Função para verificar se o caractere é um operador (+, -, *, /)
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Função para verificar a precedência do operador
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Função para converter a expressão infixa em uma árvore binária
NO* infixToExpressionTree(char expression[]) {
    PILHA* operadores = createStack();
    PILHA* operandos = createStack();
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == ' ') {
            i++;
            continue;
        } else if (expression[i] == '(') {
            push(operadores, createNode(expression[i]));
        } else if (expression[i] == ')') {
            while (!isStackEmpty(operadores) && peek(operadores)->chave != '(') {
                NO* op = pop(operadores);
                op->direita = pop(operandos);
                op->esquerda = pop(operandos);
                push(operandos, op);
            }
            pop(operadores); // Remover o '(' da pilha de operadores
        } else if (isOperator(expression[i])) {
            while (!isStackEmpty(operadores) && precedence(expression[i]) <= precedence(peek(operadores)->chave)) {
                NO* op = pop(operadores);
                op->direita = pop(operandos);
                op->esquerda = pop(operandos);
                push(operandos, op);
            }
            push(operadores, createNode(expression[i]));
        } else {
            push(operandos, createNode(expression[i]));
        }
        i++;
    }

    while (!isStackEmpty(operadores)) {
        NO* op = pop(operadores);
        op->direita = pop(operandos);
        op->esquerda = pop(operandos);
        push(operandos, op);
    }

    NO* root = pop(operandos);
    return root;
}

// Função para percorrer a árvore em ordem subárvore esquerda - raiz - subárvore direita (infixa)
void inorderTraversal(NO* root) {
    if (root != NULL) {
        inorderTraversal(root->esquerda);
        printf("%c ", root->chave);
        inorderTraversal(root->direita);
    }
}

// Função para percorrer a árvore em ordem subárvore esquerda - subárvore direita - raiz (posfixa)
void postorderTraversal(NO* root) {
    if (root != NULL) {
        postorderTraversal(root->esquerda);
        postorderTraversal(root->direita);
        printf("%c ", root->chave);
    }
}

// Função para percorrer a árvore em ordem raiz - subárvore esquerda - subárvore direita (prefixa)
void preorderTraversal(NO* root) {
    if (root != NULL) {
        printf("%c ", root->chave);
        preorderTraversal(root->esquerda);
        preorderTraversal(root->direita);
    }
}

// Função para calcular o valor da expressão aritmética representada pela árvore
int evaluateExpression(NO* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->esquerda == NULL && root->direita == NULL) {
        // Se o nó for uma folha, retorna o valor do caractere (correspondente ao valor no alfabeto ASCII)
        return root->chave - 'a' + 97;
    }

    int leftValue = evaluateExpression(root->esquerda);
    int rightValue = evaluateExpression(root->direita);

    switch (root->chave) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

// Função para imprimir a expressão matemática em notação infixa com parênteses
void Infixa(NO* root) {
    if (root != NULL) {
        if (root->esquerda != NULL && root->direita != NULL && isOperator(root->chave)) {
            printf("(");
            Infixa(root->esquerda);
            printf(" %c ", root->chave);
            Infixa(root->direita);
            printf(")");
        } else {
            printf("%c", root->chave);
        }
    }
}

// Função para imprimir a expressão matemática em notação posfixa
void Posfixa(NO* root) {
    postorderTraversal(root);
}

// Função para imprimir a expressão matemática em notação prefixa
void Prefixa(NO* root) {
    preorderTraversal(root);
}
