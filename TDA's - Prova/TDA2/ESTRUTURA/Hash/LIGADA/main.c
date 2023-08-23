#include "pac_hash_ligado.c"

int main(){
	TB_HASH tabela;
	PACIENTE p, *pacienteMaisVelho, *pacienteMenorCodigo;
	inicializahash(tabela);
	
	p = (PACIENTE){1291, "Aguinaldo", "001", 27};
	inserir(tabela,p);
	
	p = (PACIENTE){1191, "Camila", "002", 20};
	inserir(tabela, p);
	
	p = (PACIENTE){1089, "Adriano", "003", 21};
	inserir(tabela, p);
	
	mostrarHash(tabela);

	//excluir(tabela, 1291);
	//excluirPosicao(tabela, 80);

	//mostrarHash(tabela);

	
	pacienteMaisVelho = obterPacienteMaiorIdade(tabela);
	pacienteMenorCodigo = obterPacienteMenorCodigo(tabela);
	float media = calcularMediaIdades(tabela);
	int pos = buscarPosicaoPorCodigo(tabela, 1291);
	int pos2 = buscarPosicaoPorCPF(tabela, "003");
	//removerPorCpf(tabela, "003");

	printf("\nPaciente mais velho(%d): %s", pacienteMaisVelho->idade, pacienteMaisVelho->nome);
	printf("\nPaciente menor codigo(%d): %s", pacienteMenorCodigo->cod_pac, pacienteMenorCodigo->nome);
	printf("\nMedia das idades: %f)", media);
	printf("\nPosicao do codigo 003: %d", pos);
	//mostrarHash(tabela);

}
