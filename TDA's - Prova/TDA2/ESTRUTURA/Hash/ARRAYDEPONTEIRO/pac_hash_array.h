#ifndef PACIENTE_HASH_ARRAY
#define PACIENTE_HASH_ARRAY
#define N 101

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} PACIENTE;

typedef PACIENTE *TB_HASH[N];

int m_Hash (int cod_pac);
int inserir (TB_HASH tab, PACIENTE pac);
void inicializaHash (TB_HASH tab);
void mostrarHash (TB_HASH tab);
PACIENTE *busca (TB_HASH tab, int cod_pac);
int excluir (TB_HASH tab, int cod_pac);
int excluirPosicao (TB_HASH tab, int pos);
PACIENTE *obterPacienteMaiorIdade(TB_HASH tab);
PACIENTE *obterPacienteMenorCodigo(TB_HASH tab);
float calcularMediaIdades(TB_HASH tab);
int removerPorCPF(TB_HASH tab, char* cpf);
int buscarPosicaoPorCodigo(TB_HASH tab, int cod_pac);

#endif