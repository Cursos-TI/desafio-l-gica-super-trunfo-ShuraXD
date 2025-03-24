#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char pais[50];
    char codigo[10];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
} Carta;

void calcular_densidade(Carta *carta) {
    carta->densidade = (carta->area > 0) ? carta->populacao / carta->area : 0;
}

void exibir_carta(Carta carta) {
    printf("\nPaís: %s\n", carta.pais);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade demográfica: %.2f hab/km²\n", carta.densidade);
}

void exibir_menu(int atributo_excluido) {
    printf("\n=== MENU DE ATRIBUTOS ===\n");
    if (atributo_excluido != 1) printf("1. População\n");
    if (atributo_excluido != 2) printf("2. Área\n");
    if (atributo_excluido != 3) printf("3. PIB\n");
    if (atributo_excluido != 4) printf("4. Pontos turísticos\n");
    if (atributo_excluido != 5) printf("5. Densidade demográfica\n");
    printf("0. Cancelar\n");
    printf("Escolha um atributo: ");
}

int escolher_atributo(int excluido) {
    int opcao;
    bool primeira_tentativa = true;
    
    do {
        if (!primeira_tentativa) {
            printf("Opção inválida ou repetida! Tente novamente.\n");
            while(getchar() != '\n'); // Limpa buffer
        }
        primeira_tentativa = false;
        
        exibir_menu(excluido);
        scanf("%d", &opcao);
        
        if (opcao == 0) return 0; // Cancelar
    } while (opcao < 1 || opcao > 5 || opcao == excluido);
    
    return opcao;
}

float obter_valor_atributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

int comparar_atributo(Carta c1, Carta c2, int atributo) {
    float v1 = obter_valor_atributo(c1, atributo);
    float v2 = obter_valor_atributo(c2, atributo);
    

    return (atributo == 5) ? (v1 < v2 ? 1 : (v1 > v2 ? 2 : 0)) 
                           : (v1 > v2 ? 1 : (v1 < v2 ? 2 : 0));
}

void comparar_cartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("País 1: %s\n", c1.pais);
    printf("País 2: %s\n", c2.pais);
    

    const char* nomes_atributos[] = {"", "População", "Área", "PIB", 
                                    "Pontos turísticos", "Densidade demográfica"};
    
    printf("\nAtributos comparados: %s e %s\n", 
          nomes_atributos[atributo1], nomes_atributos[atributo2]);
    
    int resultado1 = comparar_atributo(c1, c2, atributo1);
    float v1_1 = obter_valor_atributo(c1, atributo1);
    float v2_1 = obter_valor_atributo(c2, atributo1);
    
    printf("\n%s: %s - %.2f vs %s - %.2f\n", nomes_atributos[atributo1],
          c1.pais, v1_1, c2.pais, v2_1);
    printf("Vencedor do 1º atributo: %s\n", 
          resultado1 == 0 ? "Empate" : (resultado1 == 1 ? c1.pais : c2.pais));
    
    int resultado2 = comparar_atributo(c1, c2, atributo2);
    float v1_2 = obter_valor_atributo(c1, atributo2);
    float v2_2 = obter_valor_atributo(c2, atributo2);
    
    printf("\n%s: %s - %.2f vs %s - %.2f\n", nomes_atributos[atributo2],
          c1.pais, v1_2, c2.pais, v2_2);
    printf("Vencedor do 2º atributo: %s\n", 
          resultado2 == 0 ? "Empate" : (resultado2 == 1 ? c1.pais : c2.pais));
    
    float soma1 = v1_1 + v1_2;
    float soma2 = v2_1 + v2_2;
    
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", c1.pais, soma1);
    printf("%s: %.2f\n", c2.pais, soma2);
    
    if (soma1 > soma2) {
        printf("\nRESULTADO FINAL: %s venceu!\n", c1.pais);
    } else if (soma1 < soma2) {
        printf("\nRESULTADO FINAL: %s venceu!\n", c2.pais);
    } else {
        printf("\nRESULTADO FINAL: Empate!\n");
    }
}

int main() {
   
    Carta carta1 = {"Brasil", "BR001", 213000000, 8515767.049, 1847000, 150};
    Carta carta2 = {"Argentina", "AR001", 45380000, 2780400, 491500, 75};
    
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);
    
    int opcao;
    
    do {
        printf("\n=== SUPER TRUNFO AVANÇADO ===\n");
        printf("1. Comparar cartas por dois atributos\n");
        printf("2. Ver informações das cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                printf("\nEscolha o PRIMEIRO atributo para comparação:");
                int atributo1 = escolher_atributo(0);
                if (atributo1 == 0) break;
                
                printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):");
                int atributo2 = escolher_atributo(atributo1);
                if (atributo2 == 0) break;
                
                comparar_cartas(carta1, carta2, atributo1, atributo2);
                break;
            }
                
            case 2:
                printf("\n=== CARTAS DISPONÍVEIS ===\n");
                exibir_carta(carta1);
                exibir_carta(carta2);
                break;
                
            case 0:
                printf("Encerrando o jogo...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            while(getchar() != '\n'); // Limpa buffer
            getchar(); // Espera Enter
        }
        
    } while (opcao != 0);
    
    return 0;
}
