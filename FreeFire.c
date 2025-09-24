/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Itens_Max_Mochila 10 //Quantidade de itens maximos da mochila
#define Max_Str 20

typedef struct {            // struct dos itens da mochila
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct 
{
    Item itens[Itens_Max_Mochila];
    int total;
} Mochila;


//Prototipo de funcoes 

void InicializarMochila(Mochila *mochila);
void Menu();
void ImpressaoItensInicial(const Mochila *mochila);
void Inserir_Item(Mochila *mochila, const char* nome, const char* tipo, int quantidade);
void Remover_Item(Mochila *mochila, const char* nome);
void Buscar_Item(Mochila *mochila, const char*nome);
void ImprimirItensCadastrados(const Mochila *mochila);
void LimparBuffer();
void LiberarMemoria();


int main (){
    Mochila mochila;
    mochila.total = 0;
    int opcao;
    char nome[Max_Str], tipo[Max_Str];
    int quantidade;

    InicializarMochila(&mochila);

    do {

        printf("===========================");
        printf("\n MOCHILA DE SOBREVIVENCIA\n");
        printf("===========================\n\n");

        ImpressaoItensInicial(&mochila);
        ImprimirItensCadastrados(&mochila);
        Menu();
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        LimparBuffer();


        switch (opcao) {
        
            case 1:
                printf("\n----- Adicionar item -----\n");
                printf("Nome do item: \n");
                fgets (nome, Max_Str, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                printf("Tipo e item(arma, municao, cura, etc): \n");
                fgets(tipo, Max_Str, stdin);
                tipo[strcspn(tipo, "\n")] = '\0';

                printf("quantidade do item: \n");
                scanf("%d", &quantidade);
                LimparBuffer();

                Inserir_Item(&mochila, nome, tipo, quantidade);
                ImprimirItensCadastrados(&mochila);
            
            break;

            case 2:
                printf("\n----- Remover item -----\n");
                printf("Digite o nome do item que voce deseja remover: \n");
                fgets(nome, Max_Str, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                Remover_Item(&mochila, nome);
                ImprimirItensCadastrados(&mochila);
            break;

            case 3:
                printf("\n----- Buscar item -----\n");
                printf("Digite o nome do item que deseja buscar: \n");
                fgets(nome, Max_Str, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                Buscar_Item(&mochila, nome);

            break;

            case 0:
            printf("Saindo da mochila \n");

            break;
        
        default:
            printf("Opcao invalida \n");
            break;
        }        

}  while (opcao != 0);
    return 0;

}

//Funcoes 
void InicializarMochila(Mochila *mochila){
        mochila ->total = 0;

}
void Menu(){

        printf("1- Adicionar item \n");
        printf("2- Remover item \n");
        printf("3- Listar itens da mochila \n");
        printf("0- Sair \n");    
}
void ImpressaoItensInicial(const Mochila *mochila){

       if (mochila->total == 0) {
        printf("Itens na mochila %d / %d.\n\n", mochila->total, Itens_Max_Mochila);
        return;
    }

    printf("\nItens na mochila (%d/%d):\n\n", mochila->total, Itens_Max_Mochila);
    for (int i = 0; i < mochila->total; i++) {
       
    }
    printf("\n");
}
void Inserir_Item(Mochila *mochila, const char* nome, const char* tipo, int quantidade){
    
    if (mochila ->total == Itens_Max_Mochila){       //Verificacao se a mochila esta cheia
        printf("Mochila cheia. \n");
        return;
    }

    strcpy(mochila->itens[mochila->total].nome, nome);  //Copia o parametro de nome de entrada para o item da mochila
    strcpy(mochila->itens[mochila->total].tipo, tipo);
    mochila->itens[mochila->total].quantidade = quantidade;
    //Copia o parametro de tipo  de entrada para o item da mochila
    
    mochila ->total++;      // Incremento dos itens da mochila

    printf(" Iten %s, do tipo %s, com quantidade %d adicionado com sucesso na mochila!\n", nome, tipo, quantidade);

}
void Remover_Item(Mochila *mochila, const char* nome){
    int i , pos = -1;

    for ( i = 0; i < mochila->total; i++){
        if (strcmp(mochila->itens[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Erro, item %s nao encontrado na mochila \n", nome);
        return;
    }
    
    for ( i = pos; i < mochila->total -1; i++) {
        mochila->itens[i] =  mochila ->itens[i + 1];
    }
    mochila->total--;
    printf("Item %s removido da mochila\n", nome);
  
}
void Buscar_Item(Mochila *mochila, const char* nome){

    for (int i = 0; i < mochila->total ; i++){
        if (strcmp(mochila->itens[i].nome, nome) == 0){
            
            printf("Item: %s, do tipo %s, com quantidade %d \n", mochila->itens[i].nome, mochila->itens[i].tipo,mochila->itens[i].quantidade);
            return;
        }
        
    }
    printf("Item nao encontrado na mochila \n");
}
void ImprimirItensCadastrados(const Mochila *mochila){
        if (mochila->total == 0){
            return;
        }
        
        for (int i = 0; i < mochila->total; i++) {
            printf("Item: %s\t|\t", mochila->itens[i].nome);
            printf("Tipo: %s\t|\t", mochila->itens[i].tipo);
            printf("Quantidade: %d\t|\t \n",mochila->itens[i].quantidade);
        
        }
        
    
}
void LimparBuffer(){
    int c;

    while ((c = getchar()) != '\n' && c != EOF);

}
void LiberarMemoria(){

}
