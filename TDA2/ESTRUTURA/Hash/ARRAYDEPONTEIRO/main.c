#include "pac_hash_array.c"

int main(){
    TB_HASH tabela;
    PACIENTE p, *pacienteMaisVelho;
    inicializaHash(tabela);

    p.cod_pac = 1291;
    p.nome = "Aguinaldo";
    p.cpf = "001";
    p.idade = 27;
    inserir(tabela, p);

    p.cod_pac = 1191;
    p.nome = "Camila";
    p.cpf = "002";
    p.idade = 20;
    inserir(tabela, p);

    p.cod_pac = 1089;
    p.nome = "Adriano";
    p.cpf = "003";
    p.idade = 22;
    inserir(tabela, p);

    mostrarHash(tabela);

    //excluir(tabela, 1291);
    //excluirPosicao(tabela, 81);

    //mostrarHash(tabela);

    pacienteMaisVelho = obterPacienteMaiorIdade(tabela);

    if (pacienteMaisVelho != NULL) {
        printf("\n Paciente de maior idade: ");
        printf("\n Código: %d", pacienteMaisVelho->cod_pac);
        printf("\n Nome: %s", pacienteMaisVelho->nome);
        printf("\n CPF: %s", pacienteMaisVelho->cpf);
        printf("\n Idade: %d", pacienteMaisVelho->idade);
    } else {
        printf("\n Nenhum paciente encontrado.");
    }

    PACIENTE *pacienteMenorCodigo = obterPacienteMenorCodigo(tabela);

    if (pacienteMenorCodigo != NULL) {
        printf("\n Paciente com menor código:");
        printf("\n Código: %d", pacienteMenorCodigo->cod_pac);
        printf("\n Nome: %s", pacienteMenorCodigo->nome);
        printf("\n CPF: %s", pacienteMenorCodigo->cpf);
        printf("\n Idade: %d", pacienteMenorCodigo->idade);
    } else {
        printf("\n Nenhum paciente encontrado.\n");
    }

    float mediaIdades = calcularMediaIdades(tabela);
    printf("\nMédia das idades: %.2f", mediaIdades);

    int remocao = removerPorCPF(tabela, "003");

    if (remocao) {
        printf("\nPaciente com CPF %s removido com sucesso.", "003");
    } else {
        printf("\nNenhum paciente com CPF %s encontrado para remoção.", "003");
    }
    mostrarHash(tabela);

    int pos = buscarPosicaoPorCodigo( tabela, 1191);

    printf("\nO paciente buscado esta na posicao: %d", pos);
}
