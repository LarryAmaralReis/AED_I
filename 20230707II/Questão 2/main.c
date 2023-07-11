#include "pac_hash_ligado.c"

int main(){
	TB_HASH tabela;
	PACIENTE p, *pr;
	inicializahash(tabela);
	
	p.cod_pac = 1291;
	p.nome = "Aguinaldo";
	p.cpf = "0000000000";
	p.idade = 27;
	inserir(tabela,p);
	
	p.cod_pac = 1191;
	p.nome = "Camila";
	p.cpf = "0000000000";
	p.idade = 20;
	inserir(tabela, p);
	
	p.cod_pac = 1089;
	p.nome = "Adriano";
	p.cpf = "0000000000";
	p.idade = 20;
	inserir(tabela, p);
	
	mostrarHash(tabela);

	excluir(tabela, 1291);
	excluirPosicao(tabela, 80);

	mostrarHash(tabela);
}
