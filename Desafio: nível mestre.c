#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de pais
typedef struct {
    char nome_pais[50];
    float populacao;
    float area;
    float pib;
    float pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para exibir o menu de atributos e receber a escolha
int exibir_menu(int primeira_escolha) {
    int escolha;
    
    printf("\nEscolha um atributo para comparar:\n");
    if (primeira_escolha != 1) {
        printf("1 - Populacao\n");
    }
    if (primeira_escolha != 2) {
        printf("2 - Area\n");
    }
    if (primeira_escolha != 3) {
        printf("3 - PIB\n");
    }
    if (primeira_escolha != 4) {
        printf("4 - Pontos Turisticos\n");
    }
    if (primeira_escolha != 5) {
        printf("5 - Densidade Demografica\n");
    }
    printf("Sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para obter o valor do atributo de uma carta
float obter_valor_atributo(const Carta* carta, int atributo) {
    switch (atributo) {
        case 1: return carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return carta->pontos_turisticos;
        case 5: return carta->densidade_demografica;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* obter_nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Invalido";
    }
}

int main() {
    // Dados da primeira carta (Brasil)
    Carta carta1;
    strcpy(carta1.nome_pais, "Brasil");
    carta1.populacao = 217.0; // Em milhoes
    carta1.area = 8515767.0;
    carta1.pib = 1600.0; // Em bilhoes de reais
    carta1.pontos_turisticos = 700.0;
    carta1.densidade_demografica = carta1.populacao / (carta1.area / 1000); // Em hab/mil km2

    // Dados da segunda carta (Argentina)
    Carta carta2;
    strcpy(carta2.nome_pais, "Argentina");
    carta2.populacao = 46.0; // Em milhoes
    carta2.area = 2780400.0;
    carta2.pib = 631.0; // Em bilhoes de reais
    carta2.pontos_turisticos = 250.0;
    carta2.densidade_demografica = carta2.populacao / (carta2.area / 1000);

    int escolha1, escolha2;
    float soma_carta1 = 0, soma_carta2 = 0;
    
    // Primeira escolha de atributo
    printf("--- Super Trunfo - Desafio Final ---\n");
    escolha1 = exibir_menu(0);

    // Segunda escolha de atributo (menu dinamico)
    printf("------------------------------------\n");
    escolha2 = exibir_menu(escolha1);

    // Validação de escolhas
    if (escolha1 < 1 || escolha1 > 5 || escolha2 < 1 || escolha2 > 5 || escolha1 == escolha2) {
        printf("\nEscolhas invalidas. Por favor, reinicie o programa.\n");
        return 1;
    }
    
    printf("\n--- Resultado da Batalha ---\n");
    
    // Comparacao do primeiro atributo
    float valor1_a1 = obter_valor_atributo(&carta1, escolha1);
    float valor2_a1 = obter_valor_atributo(&carta2, escolha1);
    const char* nome_a1 = obter_nome_atributo(escolha1);
    
    printf("\nAtributo: %s\n", nome_a1);
    printf("%s: %.2f\n", carta1.nome_pais, valor1_a1);
    printf("%s: %.2f\n", carta2.nome_pais, valor2_a1);

    // Lógica de pontos para o primeiro atributo
    if (escolha1 == 5) { // Densidade: menor valor vence
        soma_carta1 += (valor1_a1 < valor2_a1) ? valor1_a1 : 0;
        soma_carta2 += (valor2_a1 < valor1_a1) ? valor2_a1 : 0;
    } else { // Outros atributos: maior valor vence
        soma_carta1 += (valor1_a1 > valor2_a1) ? valor1_a1 : 0;
        soma_carta2 += (valor2_a1 > valor1_a1) ? valor2_a1 : 0;
    }

    // Comparacao do segundo atributo
    float valor1_a2 = obter_valor_atributo(&carta1, escolha2);
    float valor2_a2 = obter_valor_atributo(&carta2, escolha2);
    const char* nome_a2 = obter_nome_atributo(escolha2);
    
    printf("\nAtributo: %s\n", nome_a2);
    printf("%s: %.2f\n", carta1.nome_pais, valor1_a2);
    printf("%s: %.2f\n", carta2.nome_pais, valor2_a2);

    // Lógica de pontos para o segundo atributo
    if (escolha2 == 5) { // Densidade: menor valor vence
        soma_carta1 += (valor1_a2 < valor2_a2) ? valor1_a2 : 0;
        soma_carta2 += (valor2_a2 < valor1_a2) ? valor2_a2 : 0;
    } else { // Outros atributos: maior valor vence
        soma_carta1 += (valor1_a2 > valor2_a2) ? valor1_a2 : 0;
        soma_carta2 += (valor2_a2 > valor1_a2) ? valor2_a2 : 0;
    }

    // Exibicao dos resultados finais
    printf("\n--- Placar Final ---\n");
    printf("Soma dos pontos de %s: %.2f\n", carta1.nome_pais, soma_carta1);
    printf("Soma dos pontos de %s: %.2f\n", carta2.nome_pais, soma_carta2);

    // Determinacao do vencedor final
    if (soma_carta1 > soma_carta2) {
        printf("\nResultado Final: %s VENCEU a rodada!\n", carta1.nome_pais);
    } else if (soma_carta2 > soma_carta1) {
        printf("\nResultado Final: %s VENCEU a rodada!\n", carta2.nome_pais);
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}