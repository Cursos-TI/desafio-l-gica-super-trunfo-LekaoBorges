#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[5];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

int main() {

    // 1. DADOS 


    // Carta 1: Dados de São Paulo
    Carta carta1 = {
        "SP",
        "SP-1",
        "São Paulo",
        12390000,
        1521.11,
        763.8,
        50
    };

    // Carta 2:
    Carta carta2 = {
        "RJ",
        "RJ-1",
        "Rio de Janeiro",
        6770000,
        1200.25,
        370.8,
        100
    };


    // 2. CALCULAR DENSIDADE

    // (São Paulo)
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 1000000000) / (float)carta1.populacao;

    // (Rio de Janeiro)
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / (float)carta2.populacao;


    // 3. COMPARAR PIB 


    printf("Comparacao de cartas (Atributo: PIB per capita):\n\n");


    // 4. DETERMINAR VENCEDORA

    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
        printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
        printf("Resultado: Empate!\n");
    }

    return 0;
}