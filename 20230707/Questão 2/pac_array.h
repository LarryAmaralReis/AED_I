#ifndef PACIENTE_ARRAY
#define PACIENTE_ARRAY
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

#endif
