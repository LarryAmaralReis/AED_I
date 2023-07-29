#ifndef ARV_BINARIA_H
#define ARV_BINARIA_H

// Definição da estrutura do nó da árvore
typedef struct No {
    char chave;
    struct No* esquerda;
    struct No* direita;
} NO;

typedef struct {
    NO *raiz;
} ARVORE;

// Estrutura da pilha
typedef struct NoPilha {
    NO* chave;
    struct NoPilha* proximo;
} NoPilha;

typedef struct Stack {
    NoPilha* topo;
} PILHA;

NO* createNode(char chave);
PILHA* createStack();
int isStackEmpty(PILHA* pilha);
void push(PILHA* pilha, NO* chave);
NO* pop(PILHA* pilha);
NO* peek(PILHA* pilha);
int isOperator(char ch);
int precedence(char ch);
NO* infixToExpressionTree(char expressao[]);
void inorderTraversal(NO* raiz);
void postorderTraversal(NO* raiz);
void preorderTraversal(NO* raiz);
void Infixa(NO* raiz);
void Posfixa(NO* raiz);
void Prefixa(NO* raiz);
int evaluateExpression(NO* raiz);

#endif