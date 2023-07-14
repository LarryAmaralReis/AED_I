#ifndef PACIENTE_HASH_LIGADO
#define PACIENTE_HASH_LIGADO
#define N 101

typedef struct{
	int cod_pac;
	char* nome;
	char* cpf;
	int idade;
} PACIENTE;

typedef struct aux{
	PACIENTE pac;
	struct aux* proximo;;
}ELEMENTO;

typedef ELEMENTO* TB_HASH[N];

int m_hash (int cod_pac);
int inserir (TB_HASH tab, PACIENTE pac);
void inicializahash (TB_HASH tab);
void mostrarHash (TB_HASH tab);
int excluir(TB_HASH tab, int cod_pac);
int excluirPosicao (TB_HASH tab, int pos);
PACIENTE* obterPacienteMaiorIdade(TB_HASH tab);
PACIENTE* obterPacienteMenorCodigo(TB_HASH tab);
float calcularMediaIdades(TB_HASH tab);
int removerPorCpf(TB_HASH tab, char* cpf);
int buscarPosicaoPorCodigo(TB_HASH tab, int cod_pac);
int buscarPosicaoPorCPF(TB_HASH tab, char* cpf);

#endif
