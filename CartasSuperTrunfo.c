#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void exibirCarta(Carta c) {
    printf("\n--- Carta ---\n");
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: %.2f reais\n", c.pibPerCapita);
}

void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n--- Comparação ---\n");

    switch(opcao) {
        case 1: // População
            printf("Comparando População:\n");
            printf("%s: %d habitantes\n", c1.nomeCidade, c1.populacao);
            printf("%s: %d habitantes\n", c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", c1.nomeCidade, c1.area);
            printf("%s: %.2f km²\n", c2.nomeCidade, c2.area);
            if (c1.area > c2.area)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.area > c1.area)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões\n", c1.nomeCidade, c1.pib);
            printf("%s: %.2f bilhões\n", c2.nomeCidade, c2.pib);
            if (c1.pib > c2.pib)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.pib > c1.pib)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d pontos\n", c1.nomeCidade, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nomeCidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (regra invertida!)
            printf("Comparando Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", c1.nomeCidade, c1.densidade);
            printf("%s: %.2f hab/km²\n", c2.nomeCidade, c2.densidade);
            if (c1.densidade < c2.densidade)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.densidade < c1.densidade)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6: // PIB per capita
            printf("Comparando PIB per capita:\n");
            printf("%s: %.2f reais\n", c1.nomeCidade, c1.pibPerCapita);
            printf("%s: %.2f reais\n", c2.nomeCidade, c2.pibPerCapita);
            if (c1.pibPerCapita > c2.pibPerCapita)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c2.pibPerCapita > c1.pibPerCapita)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Escolha novamente.\n");
    }
}

int main() {
    // Cartas já cadastradas (exemplo fixo)
    Carta c1 = {'A', "A01", "Rio", 7000000, 1200.0, 500.0, 50, 0, 0};
    Carta c2 = {'B', "B02", "SãoPaulo", 12000000, 1500.0, 800.0, 80, 0, 0};

    // cálculos
    c1.densidade = c1.populacao / c1.area;
    c1.pibPerCapita = (c1.pib * 1000000000) / c1.populacao;
    c2.densidade = c2.populacao / c2.area;
    c2.pibPerCapita = (c2.pib * 1000000000) / c2.populacao;

    exibirCarta(c1);
    exibirCarta(c2);

    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    compararCartas(c1, c2, opcao);

    return 0;
}
