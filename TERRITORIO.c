/* 
BASE DE DADOS - TERRITÓRIO 

OBJETIVOS:

DADOS TRATADOS
--> nome
--> cor do exército
--> quantidade de tropas. 

O sistema permitirá o cadastro de 5 territórios e exibirá seus dados logo após o preenchimento.

REQUISITOS
 - Criação da struct: definir uma struct chamada Territorio com os campos char nome[30], char cor[10] e int tropas.
 - Cadastro dos territórios: o sistema deve permitir que o usuário cadastre cinco territórios informando o nome, cor do exército e o número de tropas de cada um.
 - Exibição dos dados: o sistema deve exibir as informações de todos os territórios registrados após o cadastro.

*/

// PROJETO TERRITORIO - SIMULAÇÃO DE BASE DE DADOS

// Incluir bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicao da Estrutura (Struct)
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao Principal
int main() {
    struct Territorio biblioteca[5];
    int totalTropas = 0;
    int opcao;

    do {
        // Exibe o menu
        printf("==================================\n");
        printf("     BIBLIOTECA - PARTE 1\n");
        printf("==================================\n");
        printf("1 - Cadastrar Territorio\n");
        printf("2 - Listar todos os Territorios\n");
        printf("0 - Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");

        // Leitura segura da opcao
        if (scanf("%d", &opcao) != 1) {    
            limparBufferEntrada();
            opcao = -1;  // Opcao invalida
        } else {
            limparBufferEntrada();
        }

        // Processa opcao
        switch(opcao) {
            case 1: // Cadastro novo Territorio
                printf("\n--- Cadastro de Novo Território ---\n\n");

                if (totalTropas < 6) {
                    printf("Digite o nome do Território: ");
                    fgets(biblioteca[totalTropas].nome, 30, stdin);
                    biblioteca[totalTropas].nome[strcspn(biblioteca[totalTropas].nome, "\n")] = '\0';

                    printf("Digite a cor do Território: ");
                    fgets(biblioteca[totalTropas].cor, 10, stdin);
                    biblioteca[totalTropas].cor[strcspn(biblioteca[totalTropas].cor, "\n")] = '\0';

                    printf("Digite a quantidade de Tropas: ");
                    scanf("%d", &biblioteca[totalTropas].tropas);
                    limparBufferEntrada();

                    totalTropas++;
                    printf("\nTerritório cadastrado com sucesso!\n\n");

                } else {
                    printf("\nQuantidade de Territórios cheios! Nao e possivel cadastrar mais livros.\n\n");
                }
                break;

            case 2: // Listar Territórios
                printf("\n--- Lista de Territórios Cadastrados ---\n\n");
                if (totalTropas == 0) {
                    printf("Nenhum Território foi cadastrado.\n");
                } else {
                    for (int i = 0; i < totalTropas; i++) {
                        printf("---------------------------\n");
                        printf("Território %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Cor: %s\n", biblioteca[i].cor);
                        printf("Quant. Tropas: %d\n", biblioteca[i].tropas);
                    }
                    printf("---------------------------\n");
                }
                printf("\nPressione Enter para continuar...");
                getchar(); // pausa
                break;

            case 0: // Sair
                printf("\nSaindo do sistema...\n");
                break;

            default: // Opcao invalida
                printf("\nOpcao invalida! Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

    } while(opcao != 0);

    return 0;
}
