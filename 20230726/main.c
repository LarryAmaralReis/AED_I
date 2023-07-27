#include "arv_bin_int.c"

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    // Inserting elements into the tree
    adiciona2(&minhaArvore, 24);
    adiciona2(&minhaArvore, 10);
    adiciona2(&minhaArvore, 32);
    adiciona2(&minhaArvore, 5);
    adiciona2(&minhaArvore, 12);
    adiciona2(&minhaArvore, 29);
    adiciona2(&minhaArvore, 35);

    printf("Pre-order traversal:\n");
    per_pre_ordem(minhaArvore.raiz);
    printf("\n");

    printf("In-order traversal:\n");
    per_in_ordem(minhaArvore.raiz);
    printf("\n");

    printf("Post-order traversal:\n");
    per_pos_ordem(minhaArvore.raiz);
    printf("\n");

    listarArvore(&minhaArvore);

    int x = numeroNos(minhaArvore.raiz);

    printf("\nA arvore tem %d nos", x);
    
    return 0;
}
