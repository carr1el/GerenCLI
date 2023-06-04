#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 100

typedef struct {
    int id;
    char nome[50];
    float preco;
    char descricao[MAX_DESCRICAO];
} Produto;

typedef struct {
    int id;
    char nome[50];
    char email[50];
    char cpfcnpj[20];
    char genero[20];
    char estadocivil[15];
    char telefone[15];
    char rua[100];
    char numero[7];
    char bairro[50];
    char cep[12];
    char cidade[50];
    char estado[50];
   
    Produto produtos[100];
    int numProdutos; 
} Cadastro;

void flush_in();
Cadastro* inicializar(int cap);
void novoCliente(Cadastro* cliente, int* num);
void imprimirCliente(Cadastro* cliente, int i);
void novoProduto(Cadastro* cliente, int num);
void imprimirProduto(Produto produto);

int main() {
    Cadastro* cliente;
    int cap = 20;
    int num = 0;
    int opc, i;
    printf("***GerenCLI - Gerenciamento de Produtos e Clientes***\n");
    cliente = inicializar(cap);

    do {
        printf("\nMENU\n\n");
        printf("Selecione a opcao desejada:\n");
        printf("1) Cadastrar Cliente.\n");
        printf("2) Listar Clientes\n");
        printf("3) Cadastrar Produto.\n");
        printf("4) Listar Produtos.\n");
        printf("5) Excluir Cliente.\n");
        printf("6) Sair.\n");
        printf("Opcao: ");

        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cliente = (Cadastro*)realloc(cliente, (num + 1) * sizeof(Cadastro));
                novoCliente(cliente, &num);
                printf("Cliente cadastrado com sucesso.\n");
                break;

            case 2:
                if (num == 0) {
                    printf("\nNenhum cliente cadastrado.\n");
                }
                else {
                    for (i = 0; i < num; i++) {
                        imprimirCliente(cliente, i);
                    }
                }
                break;

            case 3:
                if (num == 0) {
                    printf("\nNenhum cliente cadastrado.\n");
                }
                else {
                    novoProduto(cliente, num);
                    printf("Produto cadastrado com sucesso.\n");
                }
                break;

            case 4:
                if (num == 0) {
                    printf("\nNenhum produto cadastrado.\n");
                }
                else {
                    for (i = 0; i < num; i++) {
                        Cadastro* clienteAtual = &cliente[i];
                        for (int j = 0; j < clienteAtual->numProdutos; j++) {
                            imprimirProduto(clienteAtual->produtos[j]);
                        }
                    }
                }
                break;

          case 5: if(num == 0){
					printf("\nNenhum Cliente cadastrado.\n");
				}else{
					printf("Para apagar um cliente, necessário informar o ID.\n");
					printf("Informe o ID do cliente que deseja apagar ou digite -1 para voltar ao menu.\n");
					printf("ID: ");
					int id;
					scanf("%i", &id);
					if(id == -1) break;
					int i, k;
					for(i = 0; i < num; i++){
        	            if(id == cliente[i].id){
            	            for (k = i;k < num - 1; ++k){
                	            cliente[k] = cliente[k + 1];
                    	    }
                        	num--;
                        	cliente = (Cadastro *) realloc(cliente, (num) * sizeof(Cadastro));
                    	}
                    }
                    printf("Cliente excluido.\n");
				}
			break;

          case 6: printf("\nFechando a aplicacao.\n");
			break;

            default:
                printf("Opcao invalida.");
                flush_in();
        }
    } while (opc != 6);

    free(cliente);
    return 0;
}

void flush_in() {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
    }
}

Cadastro* inicializar(int cap) {
    Cadastro* agenda;

    agenda = (Cadastro*)malloc(sizeof(Cadastro) * cap);

    if (agenda == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    return agenda;
}

void novoCliente(Cadastro* cliente, int* num) {
    Cadastro novo;

    printf("\nCADASTRO DE CLIENTE\n");
    printf("ID: ");
    scanf("%d", &novo.id);
    flush_in();

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Email: ");
    fgets(novo.email, sizeof(novo.email), stdin);
    novo.email[strcspn(novo.email, "\n")] = '\0';

    printf("CPF/CNPJ: ");
    fgets(novo.cpfcnpj, sizeof(novo.cpfcnpj), stdin);
    novo.cpfcnpj[strcspn(novo.cpfcnpj, "\n")] = '\0';

    printf("Genero: ");
    fgets(novo.genero, sizeof(novo.genero), stdin);
    novo.genero[strcspn(novo.genero, "\n")] = '\0';

    printf("Estado Civil: ");
    fgets(novo.estadocivil, sizeof(novo.estadocivil), stdin);
    novo.estadocivil[strcspn(novo.estadocivil, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novo.telefone, sizeof(novo.telefone), stdin);
    novo.telefone[strcspn(novo.telefone, "\n")] = '\0';

    printf("Rua: ");
    fgets(novo.rua, sizeof(novo.rua), stdin);
    novo.rua[strcspn(novo.rua, "\n")] = '\0';

    printf("Numero: ");
    fgets(novo.numero, sizeof(novo.numero), stdin);
    novo.numero[strcspn(novo.numero, "\n")] = '\0';

    printf("Bairro: ");
    fgets(novo.bairro, sizeof(novo.bairro), stdin);
    novo.bairro[strcspn(novo.bairro, "\n")] = '\0';

    printf("CEP: ");
    fgets(novo.cep, sizeof(novo.cep), stdin);
    novo.cep[strcspn(novo.cep, "\n")] = '\0';

    printf("Cidade: ");
    fgets(novo.cidade, sizeof(novo.cidade), stdin);
    novo.cidade[strcspn(novo.cidade, "\n")] = '\0';

    printf("Estado: ");
    fgets(novo.estado, sizeof(novo.estado), stdin);
    novo.estado[strcspn(novo.estado, "\n")] = '\0';

    novo.numProdutos = 0;

    cliente[*num] = novo;
    (*num)++;
}

void imprimirCliente(Cadastro* cliente, int i) {
    printf("\nCLIENTE %d\n", cliente[i].id);
    printf("Nome: %s\n", cliente[i].nome);
    printf("Email: %s\n", cliente[i].email);
    printf("CPF/CNPJ: %s\n", cliente[i].cpfcnpj);
    printf("Genero: %s\n", cliente[i].genero);
    printf("Estado Civil: %s\n", cliente[i].estadocivil);
    printf("Telefone: %s\n", cliente[i].telefone);
    printf("Rua: %s\n", cliente[i].rua);
    printf("Numero: %s\n", cliente[i].numero);
    printf("Bairro: %s\n", cliente[i].bairro);
    printf("CEP: %s\n", cliente[i].cep);
    printf("Cidade: %s\n", cliente[i].cidade);
    printf("Estado: %s\n", cliente[i].estado);
}

void novoProduto(Cadastro* cliente, int num) {
    int idCliente;
    int i;

    printf("\nCADASTRO DE PRODUTO\n");
    printf("ID do Cliente: ");
    scanf("%d", &idCliente);
    flush_in();

    for (i = 0; i < num; i++) {
        if (cliente[i].id == idCliente) {
            Produto novo;
            printf("ID do Produto: ");
            scanf("%d", &novo.id);
            flush_in();

            printf("Nome do Produto: ");
            fgets(novo.nome, sizeof(novo.nome), stdin);
            novo.nome[strcspn(novo.nome, "\n")] = '\0';

            printf("Preco do Produto: ");
            scanf("%f", &novo.preco);
            flush_in();

            printf("Descricao do Produto: "); // Nova linha para adicionar descrição
            fgets(novo.descricao, sizeof(novo.descricao), stdin); // Nova linha para adicionar descrição
            novo.descricao[strcspn(novo.descricao, "\n")] = '\0'; // Nova linha para adicionar descrição

            cliente[i].produtos[cliente[i].numProdutos] = novo;
            cliente[i].numProdutos++;
            return;
        }
    }

    printf("Cliente nao encontrado.\n");
}

void imprimirProduto(Produto produto) {
    printf("\nPRODUTO %d\n", produto.id);
    printf("Nome: %s\n", produto.nome);
    printf("Preco: %.2f\n", produto.preco);
    printf("Descricao: %s\n", produto.descricao);
}
