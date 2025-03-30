#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>


//Função para calcular o SUPER-PODER
void calcularSuperPoder(int populacao, float area, float pib, int pontosTuristicos, float pibPerCapita, float densidadePopulacional, float *superPoder) {
    float inversoDensidade = (densidadePopulacional > 0) ? (1.0f / densidadePopulacional) : 0.0f;

    *superPoder = (float)populacao + area + pib + (float)pontosTuristicos + pibPerCapita + inversoDensidade;
}

// Função para exibir o resultado
void exibirResultado(char estado[], char codigo[], char nome[], int populacao, float area, float pib, int pontosTuristicos, float pibPerCapita, float densidadePopulacional, float superPoder) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo);
    printf("Cidade: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional);
    printf("PIB Per Capita: %.2f\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);
}



// Função para cadastrar os dados de uma carta
void cadastroDasCartas(char estado[], char codigo[], char nome[], int *populacao, float *area, float *pib, int *pontosTuristicos, float *densidadePopulacional, float *pibPerCapita, float *superPoder) {
    printf("\nDigite o nome do estado: ");
    scanf(" %49[^\n]", estado);

    printf("Digite o código da carta: ");
    scanf(" %49[^\n]", codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %99[^\n]", nome);

    printf("Digite a quantidade de população: ");
    scanf("%d", populacao);

    printf("Digite a área da cidade: ");
    scanf("%f", area);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", pontosTuristicos);

    printf("Digite o PIB da cidade: ");
    scanf("%f", pib);

   
    *densidadePopulacional = (*area > 0) ? (float)(*populacao) / (*area) : 0;
    *pibPerCapita = (*populacao > 0) ? *pib / (float)(*populacao) : 0;

  
    calcularSuperPoder(*populacao, *area, *pib, *pontosTuristicos, *pibPerCapita, *densidadePopulacional, superPoder);
}



void compararSuperPoder(float superPoder1, float superPoder2, char nome1[], char nome2[]) {
    printf("\nComparação de Super Poder entre %s e %s:\n", nome1, nome2);

    if (superPoder1 > superPoder2) {
        printf("%s tem um Super Poder maior (%.2f) do que %s (%.2f).\n", nome1, superPoder1, nome2, superPoder2);
    } else if (superPoder1 < superPoder2) {
        printf("%s tem um Super Poder maior (%.2f) do que %s (%.2f).\n", nome2, superPoder2, nome1, superPoder1);
    } else {
        printf("As duas cidades têm o mesmo Super Poder (%.2f).\n", superPoder1);
    }
}

void dueloDeCartas(char estado1[], int populacao1, float area1, float pib1, float superPoder1,char estado2[], int populacao2, float area2, float pib2, float superPoder2){

    float score1 = populacao1 + area1 + pib1 + superPoder1;
    float score2 = populacao2 + area2 + pib2 + superPoder2;

    if(score1 > score2){
        printf("🏆 O %s é o vencedor 🏆", estado1);
    }else{
        printf("🏆 O %s é o vencedor 🏆", estado2);
    }
    
}

int main() {
    
    char estado1[50], codigo1[50], nome1[100];
    int populacao1;
    float area1, pib1, densidadePopulacional1, pibPerCapita1, superPoder1;
    int pontosTuristicos1;

    
    char estado2[50] , codigo2[50],nome2[100];
    int populacao2;
    float area2, pib2, densidadePopulacional2, pibPerCapita2, superPoder2;
    int pontosTuristicos2;

   
    printf("\nCadastro da primeira carta:\n");
    cadastroDasCartas(estado1, codigo1, nome1, &populacao1, &area1, &pib1, &pontosTuristicos1, &densidadePopulacional1, &pibPerCapita1, &superPoder1);

 
    printf("\nCadastro da segunda carta:\n");
    cadastroDasCartas(estado2, codigo2, nome2, &populacao2, &area2, &pib2, &pontosTuristicos2, &densidadePopulacional2, &pibPerCapita2, &superPoder2);

    
    exibirResultado(estado1, codigo1, nome1, populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, densidadePopulacional1, superPoder1);
    exibirResultado(estado2, codigo2, nome2, populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, densidadePopulacional2, superPoder2);

    
    compararSuperPoder(superPoder1, superPoder2, nome1, nome2);
    printf("\n----------------------------------\n");
    printf("\nᕦ(ツ)ᕤ ⚔︎ DUELO DE CARTAS ⚔︎ ᕦ(ツ)ᕤ\n");
    printf("\n----------------------------------\n");
    dueloDeCartas(estado1, populacao1, area1, pib1, superPoder1, estado2, populacao2, area2, pib2, superPoder2);
    printf("\n----------------------------------\n");

    return 0;
}

