#ifndef INTEIRO_HASH_ARRAY
#define INTEIRO_HASH_ARRAY
#define M 11

typedef struct {
    int key;
} ELEMENTO;

typedef ELEMENTO *TB_HASH[M];

int m_Hash (int chave);
int inserir (TB_HASH tab, int chave);
int inserirLinear (TB_HASH tab, int chave);
void inicializaHash (TB_HASH tab);
void mostrarHash (TB_HASH tab);

#endif