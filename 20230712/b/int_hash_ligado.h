#ifndef INT_HASH_LIGADO
#define INT_HASH_LIGADO
#define M 11

typedef struct aux {
    int key;
    struct aux* proximo;
} ELEMENTO;

typedef ELEMENTO* TB_HASH[M];

int m_hash(int chave);
int inserir(TB_HASH tab, int chave);
void inicializahash(TB_HASH tab);
void mostrarHash(TB_HASH tab);
int excluir(TB_HASH tab, int chave);
int excluirPosicao(TB_HASH tab, int pos);

#endif