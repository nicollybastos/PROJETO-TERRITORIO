/*
PROJETO TERRITORIO - SIMULAÇÃO DE BASE DE DADOS COM ATAQUE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIOS 5

// Estrutura
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Limpa buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe territórios
void listarTerritorios(struct Territorio *territorios, int total) {
    if (total == 0) {
        printf("Nenhum território cadastrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("---------------------------\n");
        printf("%d - %s\n", i + 1, territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
    printf("---------------------------\n");
}

// Ataque entre territórios
void atacar(struct Territorio *atacante, struct Territorio *defensor) {
    if (atacante->tropas < 2) {
        printf("Território atacante não possui tropas suficientes.\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque em andamento...\n");
    printf("Atacante (%s) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) rolou: %d\n", defensor->nome, dadoDefensor);

    int poderAtaque = atacante->tropas + dadoAtacante;
    int poderDefesa = defensor->tropas + dadoDefensor;

    if (poderAtaque > poderDefesa) {
        printf(">>> Ataque venceu!\n");
        defensor->tropas--;

        if (defensor->tropas <= 0) {
            printf("Território conquistado!\n");
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;
            atacante->tropas--;
        }
    } else {
        printf(">>> Defesa venceu!\n");
        atacante->tropas--;
    }
}

int main() {
    srand(time(NULL));

    struct Territorio *territorios;
    territorios = (struct Territorio *) calloc(MAX_TERRITORIOS, sizeof(struct Territorio));

    if (territorios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int total = 0;
    int opcao;

    do {
        printf("\n==================================\n");
        printf("     SISTEMA DE TERRITORIOS\n");
        printf("==================================\n");
        printf("1 - Cadastrar Território\n");
        printf("2 - Listar Territórios\n");
        printf("3 - Atacar Território\n");
        printf("0 - Sair\n");
        printf("----------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {

            case 1:
                if (total < MAX_TERRITORIOS) {
                    printf("Nome do território: ");
                    fgets(territorios[total].nome, 30, stdin);
                    territorios[total].nome[strcspn(territorios[total].nome, "\n")] = '\0';

                    printf("Cor do exército: ");
                    fgets(territorios[total].cor, 10, stdin);
                    territorios[total].cor[strcspn(territorios[total].cor, "\n")] = '\0';

                    printf("Quantidade de tropas: ");
                    scanf("%d", &territorios[total].tropas);
                    limparBufferEntrada();

                    total++;
                    printf("Território cadastrado com sucesso!\n");
                } else {
                    printf("Limite de territórios atingido.\n");
                }
                break;

            case 2:
                listarTerritorios(territorios, total);
                break;

            case 3:
                if (total < 2) {
                    printf("É necessário pelo menos dois territórios.\n");
                } else {
                    int a, d;

                    listarTerritorios(territorios, total);

                    printf("Escolha o território atacante: ");
                    scanf("%d", &a);
                    printf("Escolha o território defensor: ");
                    scanf("%d", &d);
                    limparBufferEntrada();

                    if (a != d && a > 0 && d > 0 && a <= total && d <= total) {
                        atacar(&territorios[a - 1], &territorios[d - 1]);
                    } else {
                        printf("Escolha inválida.\n");
                    }
                }
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    free(territorios);
    return 0;
}
