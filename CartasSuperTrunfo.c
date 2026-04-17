#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void calcularAtributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1e9) / c->populacao;
}

void exibirMenu(int excluido) {
    printf("\nEscolha o atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    if (excluido != 6) printf("6 - PIB per capita\n");
    printf("Opção: ");
}

const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per capita";
        default: return "Inválido";
    }
}

float obterValor(Carta c, int atributo) {
    switch(atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return -1;
    }
}

void comparar(Carta c1, Carta c2, int a1, int a2) {
    printf("\n--- Comparação ---\n");
    float v1a1 = obterValor(c1, a1);
    float v2a1 = obterValor(c2, a1);
    float v1a2 = obterValor(c1, a2);
    float v2a2 = obterValor(c2, a2);

    // regra geral: maior vence; exceção: densidade (menor vence)
    int resultado1 = (a1 == 5) ? (v1a1 < v2a1) : (v1a1 > v2a1);
    int resultado2 = (a2 == 5) ? (v1a2 < v2a2) : (v1a2 > v2a2);

    printf("%s - %s: %.2f\n", c1.nomeCidade, nomeAtributo(a1), v1a1);
    printf("%s - %s: %.2f\n", c2.nomeCidade, nomeAtributo(a1), v2a1);
    printf("Vencedor em %s: %s\n\n", nomeAtributo(a1),
           resultado1 ? c1.nomeCidade : (v1a1 == v2a1 ? "Empate" : c2.nomeCidade));

    printf("%s - %s: %.2f\n", c1.nomeCidade, nomeAtributo(a2), v1a2);
    printf("%s - %s: %.2f\n", c2.nomeCidade, nomeAtributo(a2), v2a2);
    printf("Vencedor em %s: %s\n\n", nomeAtributo(a2),
           resultado2 ? c1.nomeCidade : (v1a2 == v2a2 ? "Empate" : c2.nomeCidade));

    // soma dos atributos
    float soma1 = v1a1 + v1a2;
    float soma2 = v2a1 + v2a2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", c1.nomeCidade, soma1);
    printf("%s: %.2f\n", c2.nomeCidade, soma2);

    printf("Resultado final: %s\n",
           (soma1 > soma2) ? c1.nomeCidade :
           (soma2 > soma1) ? c2.nomeCidade : "Empate!");
}

int main() {
    Carta c1 = {'A', "A01", "Rio", 7000000, 1200.0, 500.0, 50, 0, 0};
    Carta c2 = {'B', "B02", "SãoPaulo", 12000000, 1500.0, 800.0, 80, 0, 0};

    calcularAtributos(&c1);
    calcularAtributos(&c2);

    printf("Bem-vindo ao Super Trunfo!\n");
    printf("Você vai escolher dois atributos para comparar as cartas.\n");

    int a1, a2;
    exibirMenu(0);
    scanf("%d", &a1);

    exibirMenu(a1); // menu dinâmico, exclui o primeiro atributo
    scanf("%d", &a2);

    comparar(c1, c2, a1, a2);

    return 0;
}
