#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade; 
    float pib_per_capita; 
} Carta;


void calcular_metricas(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}


void exibir_carta(Carta carta) {
    printf("\nCarta: %s (%s)\n", carta.cidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

int main() {
   
    Carta carta1 = {
        "SP", "SP001", "São Paulo", 12300000, 1521.11, 650000, 15
    };
    
    Carta carta2 = {
        "RJ", "RJ001", "Rio de Janeiro", 6748000, 1200.27, 380000, 10
    };
    
    
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);
    
    
    printf("=== Cartas do Super Trunfo ===\n");
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    
    char atributo_escolhido[] = "populacao";
    
    printf("\n=== Comparação de Cartas ===\n");
    
    
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        printf("Atributo comparado: População\n");
        printf("%s: %d vs %s: %d\n", 
               carta1.cidade, carta1.populacao, 
               carta2.cidade, carta2.populacao);
        
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: %s (%s) venceu!\n", carta1.cidade, carta1.estado);
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: %s (%s) venceu!\n", carta2.cidade, carta2.estado);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo_escolhido, "area") == 0) {
        printf("Atributo comparado: Área\n");
        printf("%s: %.2f vs %s: %.2f\n", 
               carta1.cidade, carta1.area, 
               carta2.cidade, carta2.area);
        
        if (carta1.area > carta2.area) {
            printf("Resultado: %s (%s) venceu!\n", carta1.cidade, carta1.estado);
        } else if (carta1.area < carta2.area) {
            printf("Resultado: %s (%s) venceu!\n", carta2.cidade, carta2.estado);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo_escolhido, "pib") == 0) {
        printf("Atributo comparado: PIB\n");
        printf("%s: %.2f vs %s: %.2f\n", 
               carta1.cidade, carta1.pib, 
               carta2.cidade, carta2.pib);
        
        if (carta1.pib > carta2.pib) {
            printf("Resultado: %s (%s) venceu!\n", carta1.cidade, carta1.estado);
        } else if (carta1.pib < carta2.pib) {
            printf("Resultado: %s (%s) venceu!\n", carta2.cidade, carta2.estado);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo_escolhido, "densidade") == 0) {
        printf("Atributo comparado: Densidade Populacional (menor valor vence)\n");
        printf("%s: %.2f vs %s: %.2f\n", 
               carta1.cidade, carta1.densidade, 
               carta2.cidade, carta2.densidade);
        
        if (carta1.densidade < carta2.densidade) {
            printf("Resultado: %s (%s) venceu!\n", carta1.cidade, carta1.estado);
        } else if (carta1.densidade > carta2.densidade) {
            printf("Resultado: %s (%s) venceu!\n", carta2.cidade, carta2.estado);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        printf("Atributo comparado: PIB per capita\n");
        printf("%s: %.2f vs %s: %.2f\n", 
               carta1.cidade, carta1.pib_per_capita, 
               carta2.cidade, carta2.pib_per_capita);
        
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: %s (%s) venceu!\n", carta1.cidade, carta1.estado);
        } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
            printf("Resultado: %s (%s) venceu!\n", carta2.cidade, carta2.estado);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else {
        printf("Atributo inválido para comparação!\n");
    }
    
    return 0;
}
