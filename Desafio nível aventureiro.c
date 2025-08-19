#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char nome_pais[50];
    int populacao;
    float area;
    float densidade;
} Carta;

int main() {
    // Dados da primeira carta (Brasil)
    Carta carta1;
    strcpy(carta1.nome_pais, "Brasil");
    carta1.populacao = 217000000;
    carta1.area = 8515767.0;
    carta1.densidade = carta1.populacao / carta1.area;

    // Dados da segunda carta (Argentina)
    Carta carta2;
    strcpy(carta2.nome_pais, "Argentina");
    carta2.populacao = 46000000;
    carta2.area = 2780400.0;
    carta2.densidade = carta2.populacao / carta2.area;

    int escolha;
    
    // Menu
    printf("--- Super Trunfo ---\n");
    printf("Escolha o atributo:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - Densidade Demografica\n");
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    printf("\n");

    // Lógica de comparação
    switch (escolha) {
        case 1:
            // Populacao: maior valor vence
            if (carta1.populacao > carta2.populacao) {
                printf("O vencedor e %s.\n", carta1.nome_pais);
            } else if (carta2.populacao > carta1.populacao) {
                printf("O vencedor e %s.\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2:
            // Area: maior valor vence
            if (carta1.area > carta2.area) {
                printf("O vencedor e %s.\n", carta1.nome_pais);
            } else if (carta2.area > carta1.area) {
                printf("O vencedor e %s.\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3:
            // Densidade: menor valor vence
            if (carta1.densidade < carta2.densidade) {
                printf("O vencedor e %s.\n", carta1.nome_pais);
            } else if (carta2.densidade < carta1.densidade) {
                printf("O vencedor e %s.\n", carta2.nome_pais);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}