#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { // <----------------------- struct com as propriedades de cada tarefa
    int posicao;
    char titulo[25];
    char descricao[200];
    char estado[9]; //Pendente, Fazendo, Concluido

} Tarefa;

void exibirMenu(){
    printf("--------------------------------------------------------------\n");
    printf("ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
    printf("1. Inserir nova tarefa.\n");
    printf("2. Mostrar tarefas cadastradas.\n");
    printf("3. Buscar por tarefa.\n");
    printf("4. Editar informações de uma tarefa.\n");
    printf("5. Remover tarefa.\n");
    printf("6. Marcar conclusao de uma tarefa especifica.\n");
    printf("7. Salvar lista de tarefas em um arquivo.\n");
    printf("8. Finalizar do programa.\n");
    
    printf("--------------------------------------------------------------\n");
}

void inserirTarefa(Tarefa listaTarefas[], int *totalTarefas) {
    printf("----------------------------------------\n");
    int tamanho;

    printf("\nQuantas tarefas deseja inserir? ");
    scanf("%d", &tamanho);
    while (getchar() != '\n');
    
    listaTarefas = realloc(listaTarefas, (*totalTarefas + tamanho) * sizeof(Tarefa));

    for (int i = *totalTarefas; i < *totalTarefas + tamanho; i++) {
        listaTarefas[i].posicao = i + 1;

        printf("Digite o titulo da tarefa: ");
        scanf(" %[^\n]", listaTarefas[i].titulo);

        printf("Digite a descricao da tarefa: ");
        scanf(" %[^\n]", listaTarefas[i].descricao);

        strcpy(listaTarefas[i].estado, "Pendente"); //Todas as tarefas são criadas com o estado Pendente por padrão
    }

    *totalTarefas += tamanho;

    printf("Tarefa inserida com sucesso!!!\n");
    printf("----------------------------------------\n");
}


// Função para mostrar todas as tarefas cadastradas
void mostrarTarefas(Tarefa listaTarefas[], int totalTarefas) {
    printf("----------------------------------------\n");

    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    }

    else {
        printf("Tarefas cadastradas:\n");
        for (int i = 0; i < totalTarefas; i++) {
            printf("Posicao %d:\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);
        }
    }
    
    printf("----------------------------------------\n");

}

void buscarTarefaPorTitulo(Tarefa *listaTarefas, int length, char *titulo) {
    int resultado = 0;
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < length; i++) {
        if (strcmp(titulo, listaTarefas[i].titulo) == 0) {
            printf("RESULTADO:\n\n");

            printf("Posicao: %d\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);

            resultado = 1;
            break;
        }
    }

    if (!resultado) {
        printf("Nenhuma tarefa encontrada com o titulo %s.\n", titulo);
    }
    
    printf("--------------------------------------------------------------\n");

}

void buscarTarefaPorPosicao(Tarefa *listaTarefas, int length, int posicao) {
    int resultado = 0;
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < length; i++) {
        if (posicao == listaTarefas[i].posicao) {
            printf("--------------------------------------------------------------\n");
            printf("RESULTADO:\n\n");
            
            printf("Posicao: %d\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);
            printf("--------------------------------------------------------------\n");
            
            resultado = 1;
            break;
        }
    }

    if (!resultado) {
        printf("Nenhuma tarefa encontrada na posicao %d.\n", posicao);
    }

    printf("--------------------------------------------------------------\n");

}
void editarTarefa(Tarefa *listaTarefas, int tamanhoLista) {
    int busca;
    int resultado = 0;

    printf("--------------------------------------\n");
    printf("Editar Informacoes de uma Tarefa\n");
    printf("\nQual tarefa deseja editar?: ");//O usuário digitara a posicao da tarefa para poder edita-la
    scanf("%d", &busca);

    printf("\n");

    // Limpar o buffer de entrada
    while(getchar() != '\n');

    for(int i = 0; i < tamanhoLista; i++) {
        if(listaTarefas[i].posicao == busca) {
            printf("Posicao da tarefa: %d\n", listaTarefas[i].posicao);
            printf("Titulo da tarefa: %s\n", listaTarefas[i].titulo);
            printf("Descricao da tarefa: %s\n", listaTarefas[i].descricao);
            printf("Estado da tarefa: %s\n", listaTarefas[i].estado);
            printf("**********************************\n");

            printf("\n");

            //printf("Digite o novo 'numero' da tarefa: ");
            //scanf("%d", &listaTarefas[i].posicao);

            // Limpar o buffer de entrada
            while(getchar() != '\n');

            printf("Digite o novo 'titulo' da tarefa: ");
            fgets(listaTarefas[i].titulo, 25, stdin);
            listaTarefas[i].titulo[strcspn(listaTarefas[i].titulo, "\n")] = '\0';

            printf("Digite o novo 'descricao' da tarefa: ");
            fgets(listaTarefas[i].descricao, 200, stdin);
            listaTarefas[i].descricao[strcspn(listaTarefas[i].descricao, "\n")] = '\0';

            printf("Edicao realizada com sucesso\n");
            resultado = 1;
            break;
        }
    }

    if(!resultado) {
        printf("Tarefa nao encontrada!\n");
    }
}

void deletarTarefa(Tarefa listaTarefas[], int length){
//Recebe a posição e a reduz em 1 para funcionamento do vetor, já que o usuário inserirá sempre uma posição a mais das que se utilizam no código
    printf("Qual posicao deseja excluir?: \n");
    int posicao;
    scanf("%d", &posicao);
    posicao--;
    
//Valida se a posição é válida
    if (posicao>=0 && posicao<length){
        int i;

        for(i=posicao; i<length-1; ++i){
            listaTarefas[i] = listaTarefas[i+1];
        }
        
//Reduz o tamanho (length) do vetor em 1 para realocar sobre a tarefa à ser deletada
        length -= 1;
        listaTarefas = realloc(listaTarefas, length * sizeof(Tarefa));
    }else{
        printf("\nPosicao invalida.\n");
    }
}

void marcarConclusaoTarefa(Tarefa listaTarefas[], int length){
    int busca;
    int escolha;
    int resultado=0;

    printf("\nQual tarefa deseja marcar?: \n");
    scanf("%d", &busca);

//Limpa o buffer de entrada
    while(getchar() != '\n');

    for(int i=0; i<length; i++) {
        if(listaTarefas[i].posicao==busca) {
            printf("Numero tarefa: %d\n", listaTarefas[i].posicao);
            printf("Titulo tarefa: %s\n", listaTarefas[i].titulo);
            printf("Descricao tarefa: %s\n", listaTarefas[i].descricao);
            printf("Status tarefa: %s\n", listaTarefas[i].estado);

            printf("Opcoes de marcacao de Tarefa:\n");
            printf("1 - Pendente\n");
            printf("2 - Fazendo\n");
            printf("2 - Concluida\n");            
            printf("\nInforme o sestado desta tarefa: ");
            scanf("%d",&escolha);

            if(escolha==1){
                strcpy(listaTarefas[i].estado,"Pendente");
                break;
            }else if(escolha==2){
                strcpy(listaTarefas[i].estado,"Fazendo");
                break;
            }else if(escolha==3){
                strcpy(listaTarefas[i].estado,"Concluida");
            }else{
                printf("Opcao invalida");
                break;
            }
            printf("Marcacao realizada com sucesso\n");

            resultado=1;
            break;
        }
    }

    if(!resultado) {
        printf("Tarefa nao encontrada!\n");
    }
}

int main() {
    int opcaoMenu;

Tarefa listaTarefas[100];
    int tamanhoLista = 0;

    while(opcaoMenu != 8){

        //Exibe menu inicial
        exibirMenu();
        
        printf("Digite um numero para realizar alguma acao: \n");
        scanf("%d", &opcaoMenu);

        //Finalizar execucao do script
        if (opcaoMenu == 8){
            printf("Programa sendo finalizado...\n");
            exit(1);
        }

        //Estrutura basica do documento
        switch(opcaoMenu) {
            case 1:
                inserirTarefa(listaTarefas,&tamanhoLista);
                break;

            case 2: 
                mostrarTarefas(listaTarefas,tamanhoLista);
                break;

            case 3: 
                int resposta;
                int length = sizeof(listaTarefas) / sizeof(listaTarefas[0]);
                printf("Escolha uma das opcoes abaixo para buscar tarefas por titulo ou posicao:\n");
                printf("0 - Titulo\n");
                printf("1 - Posicao\n");
                scanf("%d",&resposta);

                getchar();

                if(resposta == 0){
                    char titulo[25];

                    printf("Qual o titulo da tarefa que você deseja buscar?\n");

                    if(fgets(titulo, sizeof(titulo), stdin) != NULL){
                        titulo[strcspn(titulo, "\n")] = '\0'; // Remover o caractere de nova linha
                        buscarTarefaPorTitulo(listaTarefas, length, titulo);
                    }

                    else{
                        printf("Por favor, insira um titulo valido\n");
                    }

                }
                
                else if(resposta == 1){
                    int posicao;

                    printf("Qual a posicao da tarefa que você deseja buscar? \n");
                    scanf("%d",&posicao);

                    buscarTarefaPorPosicao(listaTarefas, length, posicao);
                }

                else{
                    printf("Comando invalido. Tente novamente!\n");
                    continue;
                }
                break;

            case 4:
                editarTarefa(listaTarefas, tamanhoLista);
                break;

            case 5:
                deletarTarefa(listaTarefas, &length);
                break;

            case 6:
                marcarConclusaoTarefa(listaTarefas, length);

                break;

            case 7:
                printf("Salvar lista de tarefas em um arquivo\n");
                break;

            default:
                printf("Número inválido, tente novamente! \n");
        }
    }

    return 0;
}
