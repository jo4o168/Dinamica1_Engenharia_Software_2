#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct Dados, que representa um livro
typedef struct {
    char titulo[30];  // título do livro
    char autor[30];   // autor do livro
    int ano;          // ano de publicação
} Dados;

// Função para buscar livro pelo título
void buscaTitulo(const char *p) {
    FILE *t;
    char titulo[30], autor[30];
    int ano;
    int e = 0;  // flag para indicar se encontrou o livro

    t = fopen("t.txt", "r");  // abre o arquivo em modo leitura
    if (t == NULL) {
        puts("Erro ao abrir arquivo.");  // verifica se o arquivo existe
        return;
    }

    // lê cada registro do arquivo enquanto houver linhas
    while (fscanf(t, "%29s\n%29s\n%d\n\n", titulo, autor, &ano) == 3) {
        if (strcmp(titulo, p) == 0) {  // compara título do arquivo com a busca
            printf("\nEncontrado:\nTitulo: %s\nAutor: %s\nAno: %d\n", titulo, autor, ano);
            e = 1;  // marca que encontrou
        }
    }

    fclose(t);  // fecha o arquivo

    if (e == 0) {
        printf("\nTitulo '%s' nao encontrado.\n", p);  // mensagem se não encontrar
    }
}

// Função para buscar livro pelo autor
void buscaAutor(const char *p) {
    FILE *t;
    char titulo[30], autor[30];
    int ano;
    int e = 0;  // flag para indicar se encontrou o autor

    t = fopen("t.txt", "r");  // abre o arquivo em modo leitura
    if (t == NULL) {
        puts("Erro ao abrir arquivo.");
        return;
    }

    // percorre todos os registros
    while (fscanf(t, "%29s\n%29s\n%d\n\n", titulo, autor, &ano) == 3) {
        if (strcmp(autor, p) == 0) {  // compara autor do arquivo com a busca
            printf("\nEncontrado:\nTitulo: %s\nAutor: %s\nAno: %d\n", titulo, autor, ano);
            e = 1;
        }
    }

    fclose(t);

    if (e == 0) {
        printf("\nAutor '%s' nao encontrado.\n", p);
    }
}

// Função para buscar livro pelo ano
void buscaAno(int anoBusca) {
    FILE *t;
    char titulo[30], autor[30];
    int ano;
    int e = 0;  // flag para indicar se encontrou algum livro

    t = fopen("t.txt", "r");  // abre arquivo em modo leitura
    if (t == NULL) {
        puts("Erro ao abrir arquivo.");
        return;
    }

    // percorre todos os registros
    while (fscanf(t, "%29s\n%29s\n%d\n\n", titulo, autor, &ano) == 3) {
        if (ano == anoBusca) {  // compara ano do livro com a busca
            printf("\nEncontrado:\nTitulo: %s\nAutor: %s\nAno: %d\n", titulo, autor, ano);
            e = 1;
        }
    }

    fclose(t);

    if (e == 0) {
        printf("\nNenhum livro do ano '%d' encontrado.\n", anoBusca);
    }
}

// Função principal
int main(void) {
    Dados dados;    // variável para armazenar dados temporários do livro
    FILE *t;        // ponteiro para manipulação do arquivo
    int opcao;      // opção escolhida pelo usuário

    printf("OLA, SEJA BEM VINDO A SUA BIBLIOTECA PESSOAL\n");

    for (;;) {  // loop infinito do menu
        printf("\n===== MENU =====\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por Titulo\n");
        printf("3. Buscar livro por Autor\n");
        printf("4. Buscar livro por Ano\n");
        printf("0. Sair\n:");
        scanf("%d", &opcao);  // lê a opção do usuário

        switch (opcao) {
            case 1:  // adicionar livro
                printf("Titulo: ");
                scanf("%29s", dados.titulo);  // lê o título

                printf("Autor: ");
                scanf("%29s", dados.autor);   // lê o autor

                printf("Ano: ");
                scanf("%d", &dados.ano);      // lê o ano

                t = fopen("t.txt", "a");      // abre arquivo para acrescentar dados
                if (t == NULL) {
                    printf("Erro ao abrir o arquivo para escrita.\n");
                    break;
                }

                fprintf(t, "%s\n%s\n%d\n\n", dados.titulo, dados.autor, dados.ano);  // escreve no arquivo
                fclose(t);  // fecha arquivo

                printf("Livro adicionado com sucesso!\n");
                break;

            case 2: {  // buscar por título
                char B[30];
                printf("\nDigite o titulo para buscar: ");
                scanf("%29s", B);
                buscaTitulo(B);
                break;
            }

            case 3: {  // buscar por autor
                char B[30];
                printf("\nDigite o autor para buscar: ");
                scanf("%29s", B);
                buscaAutor(B);
                break;
            }

            case 4: {  // buscar por ano
                int anoBusca;
                printf("\nDigite o ano para buscar: ");
                scanf("%d", &anoBusca);
                buscaAno(anoBusca);
                break;
            }

            case 0:  // sair do programa
                printf("\nEncerrando o programa...\n");
                return 0;  // termina o loop e o programa

            default:  // opção inválida
                printf("Opcao invalida, tente novamente.\n");
                break;
        }
    }

    return 0;
}