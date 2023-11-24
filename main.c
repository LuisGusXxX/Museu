#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int totalIngressosVendidos = 0;
float totalArrecadado = 0.0;
int ingressosVendidos[3] = {0};
int ingressosNoCarrinho = 0;
int temaCarrinho[4] = {0};
int temasNoCarrinho = 0;

const char *nomesTemas[] = {
    "Arte Moderna",
    "Jogos olimpicos",
    "100 anos Drumon",
    "Aniversario de SP"
};

const char *formasPagamento[] = {
    "Cartao de Credito",
    "Cartao de Debito",
    "Dinheiro",
    "Pix"
};
//NOTA FISCAL
void exibirNotaFiscal() {
    system("cls");
    puts("NOTA FISCAL DAS COMPRAS DE INGRESSOS:\n");
    printf("Total de ingressos vendidos: %d\n", totalIngressosVendidos);
    printf("Valor total arrecadado: R$%.2f\n", totalArrecadado);
    printf("Quantidade de ingressos vendidos: Inteiro - %d, Meia - %d, Gratuito - %d\n", ingressosVendidos[0], ingressosVendidos[1], ingressosVendidos[2]);
    printf("Temas no carrinho: ");
    for (int i = 0; i < temasNoCarrinho; i++) {
        printf("%s ", nomesTemas[temaCarrinho[i] - 1]);
    }
    printf("\n");
    printf("Quantidade de ingressos no carrinho: %d\n", ingressosNoCarrinho);
    printf("\nFormas de pagamento:\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s\n", i + 1, formasPagamento[i]);
    }
    int escolhaPagamento;
    printf("\nEscolha a forma de pagamento (1-4): ");
    scanf("%d", &escolhaPagamento);
    printf("Forma de pagamento escolhida: %s\n", formasPagamento[escolhaPagamento - 1]);
    printf("\nAPERTE ENTER PARA VOLTAR AO MENU: ");
    getchar();
    getchar();
    system("cls");

    ingressosNoCarrinho = 0;
    temasNoCarrinho = 0;
    for (int i = 0; i < 4; i++) {
        temaCarrinho[i] = 0;
    }

    printf("\n Gerando arquivo CSV...\n");

    salvarDadosCSV();
    printf("Arquivo CSV gerado com sucesso!\n");

    }

//ARQUIVO CVS
void salvarDadosCSV() {
    FILE *arquivo;
    arquivo = fopen( "C:\\MainC\\museu_multitematico\\Dados Museu\\dados_museu.csv ", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
      ingressosNoCarrinho = 0;
    temasNoCarrinho = 0;
    for (int i = 0; i < 4; i++) {
        temaCarrinho[i] = 0;
     }


     }

    fprintf(arquivo, "Total de ingressos vendidos, Valor total arrecadado, Ingressos Inteiro, Ingressos Meia, Ingressos Gratuito\n");
    fprintf(arquivo, "%d, %.2f, %d, %d, %d\n", totalIngressosVendidos, totalArrecadado, ingressosVendidos[0], ingressosVendidos[1], ingressosVendidos[2]);

    fclose (arquivo);
}

//CARINHO DE COMPRAS
void exibirCarrinho() {
    if (temasNoCarrinho > 0) {
        printf("Temas no carrinho: ");
        for (int i = 0; i < temasNoCarrinho; i++) {
            printf("%s ", nomesTemas[temaCarrinho[i] - 1]);
        }
        printf("\n");
    } else {
        printf("Carrinho de temas vazio. Selecione pelo menos um tema.\n");
    }

    if (ingressosNoCarrinho > 0) {
        printf("Ingressos no carrinho: %d\n", ingressosNoCarrinho);
    }
    printf("\n");
}


void comprarIngresso() {
    int tipoIngresso;
    float preco = 0.0;
    char tipo[20];

//TABELA DE PREÇO
    while (1) {
        exibirCarrinho();

        puts("***** TABELA DE PRECO DOS INGRESSOS: *****\n");
        printf("1 - INGRESSOS INTEIRO.....R$200,00\n");
        printf("2 - INGRESSOS MEIA.......R$100,00\n");
        printf("3 - INGRESSOS GRATUITOS.....R$0,00\n");
        printf("4 - Sair e finalizar a compra\n");

        printf("\nEscolha o tipo de ingresso (1-3) ou (4 para finalizar a compra): ");
        scanf("%d", &tipoIngresso);

        if (tipoIngresso == 4) {
            system("cls");
            exibirNotaFiscal();
            break;
        }

        if (tipoIngresso >= 1 && tipoIngresso <= 3) {
            system("cls");
            switch (tipoIngresso) {
                case 1:
                    strcpy(tipo, "INTEIRO");
                    preco = 200.0;
                    ingressosVendidos[0]++;
                    break;
                case 2:
                    strcpy(tipo, "MEIA");
                    preco = 100.0;
                    ingressosVendidos[1]++;
                    break;
                case 3:
                    strcpy(tipo, "GRATUITO");
                    preco = 0.0;
                    ingressosVendidos[2]++;
                    break;

                     case 5:
            exibirCreditos();
            salvarDadosCSV(); // Chama a função para gerar o arquivo CSV ao exibir os créditos
            break;

            }

            printf("Voce escolheu o ingresso do tipo %s.\n", tipo);
            totalIngressosVendidos++;
            totalArrecadado += preco;
            ingressosNoCarrinho++;
        } else {
            getchar();
            system("cls");
            puts("OPCAO INVALIDA. POR FAVOR, ESCOLHA UM NUMERO DE 1, 2 ou 3.");
        }
    }
}
//TABELA MENU DE TEMAS
void selecionarTema() {
    int temaMuseu;
    if (temasNoCarrinho < 4) {
        puts("***** TABELA DE TEMAS DO MUSEU: *****\n");
        printf("1 - Tema 1: Arte Moderna\n");
        printf("2 - Tema 2: Jogos olimpicos\n");
        printf("3 - Tema 3: 100 anos Drumon\n");
        printf("4 - Tema 4: Anivesario de SP\n");
        printf("5 - Sair e voltar ao menu principal\n");

        printf("\nEscolha o tema do museu (1-4) ou (5 para sair): ");
        scanf("%d", &temaMuseu);

        if (temaMuseu == 5) {
            system("cls");
        } else if (temaMuseu >= 1 && temaMuseu <= 4) {
            system("cls");
            int index = 0;
            while (temaCarrinho[index] != 0 && index < 4) {
                index++;
            }
            if (index < 4) {
                temaCarrinho[index] = temaMuseu;
                temasNoCarrinho++;
                printf("Tema %s foi adicionado ao carrinho.\n", nomesTemas[temaMuseu - 1]);
            } else {
                printf("O carrinho de temas está cheio (limite de 4 temas). Avance para a compra de ingressos ou finalize temas existentes.\n");
            }
        } else {
            getchar();
            system("cls");
            puts("OPCAO INVALIDA. POR FAVOR, ESCOLHA UM NUMERO DE 1, 2, 3 ou 4.");
        }
    } else {
        printf("O carrinho de temas está cheio (limite de 4 temas). Avance para a compra de ingressos ou finalize temas existentes.\n");
    }
}
//FUNÇAO 5 SAIR DO PROGRAMA
void exibirCreditos() {
    puts("CREDITOS\n");
    puts("ESTE PROGRAMA FOI FEITO POR USUARIOS.");
    printf("APERTE ENTER PARA VOLTAR AO MENU: ");
    getchar();
    system("cls");
}


//MENU INICIAL
int main() {
    int escolha;

    puts("****** BEM VINDO AO MUSEU MULTITEMATICO ******\n");

    while (1) {
        exibirCarrinho();

        puts("\n*** ESCOLHA UMA OPCAO ABAIXO: ***\n");
        puts("1 - SELECIONAR TEMA DO MUSEU\n");
        puts("2 - COMPRA DE INGRESSOS\n");
        puts("3 - VERIFICAR TOTAL DE INGRESSOS VENDIDOS E VALOR ARRECADADO\n");
        puts("4 - SAIR DO PROGRAMA\n");
        printf("DIGITE O NUMERO ESCOLHIDO E APERTE ENTER: ");
        scanf("%d", &escolha);
        system("cls");

        switch (escolha) {
            case 1:
                if (temasNoCarrinho < 4) {
                    selecionarTema();
                } else {
                    printf("O carrinho de temas está cheio (limite de 4 temas). Avance para a compra de ingressos ou finalize temas existentes.\n");
                }
                break;
            case 2:
                if (temasNoCarrinho > 0) {
                    comprarIngresso();
                } else {
                    printf("Por favor, selecione pelo menos um tema antes de avançar para a compra de ingressos.\n");
                }
                break;
            case 3:
                system("cls");
                printf("\nTotal de ingressos vendidos: %d\n", totalIngressosVendidos);
                printf("\nValor total arrecadado: R$%.2f\n", totalArrecadado);
                printf("\nAPERTE ENTER PARA VOLTAR AO MENU: ");
                getchar();
                getchar();
                system("cls");
                break;
            case 4:
                puts("OBRIGADO POR ESCOLHER NOSSO MUSEU");
                exit(0);
            case 5:
                exibirCreditos();
                break;
            default:
                getchar();
                system("cls");
                puts("OPCAO INVALIDA. POR FAVOR, SELECIONE UM NUMERO DA LISTA.");
                printf("APERTE ENTER PARA VOLTAR AO MENU: ");
                getchar();
        }
    }

    return 0;
}
