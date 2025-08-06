#include <stdio.h>

int main() {
    // ----------------------------------------------------
    // DECLARAÇÃO DE VARIÁVEIS PARA A PRIMEIRA CARTA
    // ----------------------------------------------------
    char estado1;
    char codigo1[5];
    char nome_cidade1[50];
    unsigned long int populacao1; // Tipo para acomodar numeros grandes
    float area1;
    float pib1;
    int pontos_turisticos1;

    // ----------------------------------------------------
    // DECLARAÇÃO DE VARIÁVEIS PARA A SEGUNDA CARTA
    // ----------------------------------------------------
    char estado2;
    char codigo2[5];
    char nome_cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    // Variáveis para armazenar os valores calculados
    float densidade_populacional1, pib_per_capita1, super_poder1;
    float densidade_populacional2, pib_per_capita2, super_poder2;

    // Variáveis para armazenar o resultado das comparações (1 se Carta 1 vence, 0 se Carta 2 vence)
    int resultado_populacao, resultado_area, resultado_pib, resultado_pontos,
        resultado_densidade, resultado_pib_per_capita, resultado_super_poder;

    // ----------------------------------------------------
    // SOLICITAÇÃO E LEITURA DOS DADOS DA PRIMEIRA CARTA
    // ----------------------------------------------------
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado1);
    
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]s", nome_cidade1);
    
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao1);
    
    printf("Digite a Area (em km^2): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos1);
    
    printf("\n");
    
    // ----------------------------------------------------
    // SOLICITAÇÃO E LEITURA DOS DADOS DA SEGUNDA CARTA
    // ----------------------------------------------------
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado2);
    
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]s", nome_cidade2);
    
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a Area (em km^2): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // ----------------------------------------------------
    // CÁLCULOS DOS ATRIBUTOS DERIVADOS
    // ----------------------------------------------------
    
    // Carta 1
    densidade_populacional1 = (float)populacao1 / area1;
    pib_per_capita1 = pib1 / (float)populacao1;
    
    // Carta 2
    densidade_populacional2 = (float)populacao2 / area2;
    pib_per_capita2 = pib2 / (float)populacao2;
    
    // ----------------------------------------------------
    // CÁLCULO DO SUPER PODER
    // ----------------------------------------------------
    
    // Carta 1
    super_poder1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);
    
    // Carta 2
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);
    
    // ----------------------------------------------------
    // EXIBIÇÃO DE INFORMAÇÕES CADASTRADAS E CALCULADAS
    // ----------------------------------------------------
    printf("\n--- Informacoes das Cartas ---\n");
    
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);
    
    printf("\n");
    
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);
    
    // ----------------------------------------------------
    // COMPARAÇÃO DAS CARTAS E EXIBIÇÃO DO RESULTADO
    // ----------------------------------------------------
    
    // Atribui 1 se a Carta 1 vence, 0 se a Carta 2 vence.
    // Para Densidade, o menor valor vence.
    resultado_populacao = (populacao1 > populacao2);
    resultado_area = (area1 > area2);
    resultado_pib = (pib1 > pib2);
    resultado_pontos = (pontos_turisticos1 > pontos_turisticos2);
    resultado_densidade = (densidade_populacional1 < densidade_populacional2); // Regra invertida
    resultado_pib_per_capita = (pib_per_capita1 > pib_per_capita2);
    resultado_super_poder = (super_poder1 > super_poder2);
    
    printf("\n--- Comparacao de Cartas ---\n");
    printf("População: %s (%d)\n", resultado_populacao ? "Carta 1 venceu" : "Carta 2 venceu", resultado_populacao);
    printf("Área: %s (%d)\n", resultado_area ? "Carta 1 venceu" : "Carta 2 venceu", resultado_area);
    printf("PIB: %s (%d)\n", resultado_pib ? "Carta 1 venceu" : "Carta 2 venceu", resultado_pib);
    printf("Pontos Turisticos: %s (%d)\n", resultado_pontos ? "Carta 1 venceu" : "Carta 2 venceu", resultado_pontos);
    printf("Densidade Populacional: %s (%d)\n", resultado_densidade ? "Carta 1 venceu" : "Carta 2 venceu", resultado_densidade);
    printf("PIB per Capita: %s (%d)\n", resultado_pib_per_capita ? "Carta 1 venceu" : "Carta 2 venceu", resultado_pib_per_capita);
    printf("Super Poder: %s (%d)\n", resultado_super_poder ? "Carta 1 venceu" : "Carta 2 venceu", resultado_super_poder);
    
    return 0;
}