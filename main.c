#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { // <----------------------- struct com as propriedades de cada tarefa
    int posicao;
    char titulo[60];
    char descricao[300];
    char estado[14]; //Pendente, concluido, nao concluido

} Tarefa;

void exibirMenu(){
    printf("--------------------------------------------------------------\n");
    
    printf("ESCOLHA UMA DAS OPCOES ABAIXO: \n\n");
    
    printf("1. Inserir nova tarefa.\n");
    printf("2. Mostrar tarefas cadastradas.\n");
    printf("3. Buscar por tarefa.\n");
    printf("4. Editar informacoes de uma tarefa.\n");
    printf("5. Remover tarefa.\n");
    printf("6. Marcar conclusao de uma tarefa especifica.\n");
    printf("7. Salvar lista de tarefas em um arquivo.\n");
    printf("8. Finalizar o programa.\n");
    
    printf("--------------------------------------------------------------\n\n");

}

void inserirTarefa(Tarefa **listaTarefas, int *totalTarefas) {
    printf("--------------------------------------------------------------\n");
    
    int tamanho;

    printf("\nQuantas tarefas deseja inserir? ");
    scanf("%d", &tamanho);
    printf("\n");
    while (getchar() != '\n');
    
    *listaTarefas = realloc(*listaTarefas, (*totalTarefas + tamanho) * sizeof(Tarefa));

    for (int i = *totalTarefas; i < *totalTarefas + tamanho; i++) {
        (*listaTarefas)[i].posicao = i + 1;

        printf("Digite o titulo da tarefa: ");
        scanf(" %[^\n]", (*listaTarefas)[i].titulo);

        printf("Digite a descricao da tarefa: ");
        scanf(" %[^\n]", (*listaTarefas)[i].descricao);

        //Todas as tarefas sao criadas com o estado Pendente por padrao
        strcpy((*listaTarefas)[i].estado, "Pendente");
        printf("\n");
    }

    *totalTarefas += tamanho;

    printf("\nTarefas inseridas com sucesso!!!\n");
    
    printf("--------------------------------------------------------------\n\n");
}


// Funcao para mostrar todas as tarefas cadastradas
void mostrarTarefas(Tarefa *listaTarefas, int totalTarefas) {
    printf("--------------------------------------------------------------\n");

    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    }

    else {
        printf("Tarefas cadastradas:\n");
        for (int i = 0; i < totalTarefas; i++) {
            printf("\n");
            
            printf("Posicao %d:\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);
        }
    }
    
    printf("--------------------------------------------------------------\n\n");
}

void buscarTarefaPorTitulo(Tarefa *listaTarefas, int length) {
    char titulo[60];
    int resultado = 0;
    
    printf("--------------------------------------------------------------\n");
    
    printf("Qual o titulo da tarefa que voce deseja buscar?\n");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Remover o caractere de nova linha

    for (int i = 0; i < length; i++) {
        if (strcmp(titulo, listaTarefas[i].titulo) == 0) {
            printf("#######################################\n");

            printf("\nRESULTADO:\n\n");

            printf("Posicao: %d\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);

            printf("#######################################\n");

            resultado = 1;
            break;
        }
    }

    if (!resultado) {
        printf("Nenhuma tarefa encontrada com o titulo %s.\n", titulo);
    }
    
    printf("--------------------------------------------------------------\n\n");
}

void buscarTarefaPorPosicao(Tarefa *listaTarefas, int length) {
    int resultado = 0;
    int posicao;

    printf("--------------------------------------------------------------\n");

    printf("Qual a posicao da tarefa que voce deseja buscar? \n");
    scanf("%d",&posicao);

    for (int i = 0; i < length; i++) {
        if (posicao == listaTarefas[i].posicao) {
            printf("#######################################\n");
            
            printf("\nRESULTADO:\n\n");
            
            printf("Posicao: %d\n", listaTarefas[i].posicao);
            printf("Titulo: %s\n", listaTarefas[i].titulo);
            printf("Descricao: %s\n", listaTarefas[i].descricao);
            printf("Estado: %s\n", listaTarefas[i].estado);
            
            printf("#######################################\n");
            
            resultado = 1;
            break;
        }
    }

    if (!resultado) {
        printf("Nenhuma tarefa encontrada na posicao %d.\n", posicao);
    }

    printf("--------------------------------------------------------------\n\n");

}

void editarTarefa(Tarefa *listaTarefas, int tamanhoLista) {
    int busca;
    int resultado = 0;

    printf("--------------------------------------------------------------\n");

    printf("\nDigite a 'Posicao' da tarefa que deseja editar?: ");//O usuário digitara a posicao da tarefa para poder edita-la
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
          printf("********************************\n");

          printf("\n");

          // Limpar o buffer de entrada
          while(getchar() != '\n');

          printf("Digite o novo 'titulo' da tarefa: ");
          fgets(listaTarefas[i].titulo, 60, stdin);
          listaTarefas[i].titulo[strcspn(listaTarefas[i].titulo, "\n")] = '\0';

          printf("Digite o novo 'descricao' da tarefa: ");
          fgets(listaTarefas[i].descricao, 300, stdin);
          listaTarefas[i].descricao[strcspn(listaTarefas[i].descricao, "\n")] = '\0';

          printf("Edicao realizada com sucesso\n");
          resultado = 1;
          break;
        }
    }

    if(!resultado) {
        printf("Tarefa nao encontrada!\n");
    }

    printf("--------------------------------------------------------------\n\n");
}

void deletarTarefa(Tarefa **listaTarefas, int *totalTarefas) {
    printf("--------------------------------------------------------------\n");
    
    //Recebe a posicao e a reduz em 1 para funcionamento do vetor, ja que o usuario inserira sempre uma posicao a mais das que se utilizam no codigo
    int posicao;
    printf("Qual posicao deseja excluir? \n");
    scanf("%d", &posicao);
    posicao--;
    
    //Valida se a posicao eh valida
    if (posicao>=0 && posicao<*totalTarefas){
        int i;

        for(i=posicao; i<*totalTarefas-1; ++i){
            (*listaTarefas)[i] = (*listaTarefas)[i+1];
        }
        
    //Reduz o tamanho (totalTarefas) do vetor em 1 para realocar sobre a tarefa a ser deletada
        *totalTarefas -= 1;
        *listaTarefas = realloc(*listaTarefas, (*totalTarefas) * sizeof(Tarefa));

    }else{
        printf("\nPosicao invalida.\n");
    }

    printf("--------------------------------------------------------------\n\n");
}

void marcarConclusaoTarefa(Tarefa *listaTarefas, int totalTarefas){
    int busca;
    int escolha;
    int resultado=0;

    printf("--------------------------------------------------------------\n");

    printf("\nQual tarefa deseja marcar? \n");
    scanf("%d", &busca);

    //Limpa o buffer de entrada
    while(getchar() != '\n');

    for(int i=0; i<totalTarefas; i++) {
        if(listaTarefas[i].posicao==busca) {
            printf("Numero tarefa: %d\n", listaTarefas[i].posicao);
            printf("Titulo tarefa: %s\n", listaTarefas[i].titulo);
            printf("Descricao tarefa: %s\n", listaTarefas[i].descricao);
            printf("Status tarefa: %s\n", listaTarefas[i].estado);

            printf("Opcoes de marcacao de Tarefa:\n");
            printf("1 - Pendente\n");
            printf("2 - Fazendo\n");
            printf("3 - Concluida\n");            
            printf("\nInforme o estado desta tarefa: ");
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

    printf("--------------------------------------------------------------\n\n");
}

void salvarEmArquivo(Tarefa* listaTarefas, int tamanhoLista){
    int escolha;
    FILE *arquivo;
    arquivo = fopen("tarefas.txt","w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    printf("Digite o 'Estado' da tarefa de acordo com as opcoes:\n");
    printf("0 - Concluido\n");
    printf("1 - Nao Concluido\n");
    printf("\n");

    for(int i = 0; i < tamanhoLista; i++){
        printf("Posicao: %d\n",listaTarefas[i].posicao);
        printf("Titulo: %s\n",listaTarefas[i].titulo);
        printf("Descricao: %s\n",listaTarefas[i].descricao);
        printf("Estado: ");
        scanf("%d",&escolha);
        printf("\n");

        if(escolha == 0){
            strcpy(listaTarefas[i].estado,"Concluido");
            fprintf(arquivo, "%d;%s;%s;%s\n",listaTarefas[i].posicao, listaTarefas[i].titulo, listaTarefas[i].descricao, listaTarefas[i].estado);
            
        }else if(escolha == 1){
            strcpy(listaTarefas[i].estado,"Nao Concluido");
            fprintf(arquivo, "%d;%s;%s;%s\n",listaTarefas[i].posicao, listaTarefas[i].titulo, listaTarefas[i].descricao, listaTarefas[i].estado);
            
        }else{
            printf("Opcao Invalida!\n");
        }

    }

    printf("Arquivo criado com sucesso\n");
    
    fclose(arquivo);
}

int main() {
    int opcaoMenu = 0;

    Tarefa *listaTarefas = (Tarefa*) malloc(sizeof(Tarefa));
    
    int *tamanhoLista = (int *) malloc(sizeof(int));
    *tamanhoLista = 0;

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
                inserirTarefa(&listaTarefas,tamanhoLista);
                break;

            case 2: 
                mostrarTarefas(listaTarefas,*tamanhoLista);
                break;

            case 3:

                printf("Escolha uma das opcoes abaixo para buscar tarefas por titulo ou posicao:\n");
                
                printf("0 - Titulo\n");
                printf("1 - Posicao\n");
                int resposta;
                scanf("%d",&resposta);

                getchar(); // Limpar o buffet de entrada;

                if(resposta == 0){
                    buscarTarefaPorTitulo(listaTarefas, *tamanhoLista);
                }
                else if(resposta == 1){
                    buscarTarefaPorPosicao(listaTarefas, *tamanhoLista);
                }

                else{
                    printf("Comando invalido. Tente novamente!\n");
                }
                
                break;

            case 4:
                editarTarefa(listaTarefas, *tamanhoLista);
                break;

            case 5:
                deletarTarefa(&listaTarefas, tamanhoLista);
                break;

            case 6:
                marcarConclusaoTarefa(listaTarefas, *tamanhoLista);
                break;

            case 7:
                salvarEmArquivo(listaTarefas, tamanhoLista);
                break;

            default:
                printf("Número inválido, tente novamente! \n");
        }
    }

    return 0;
}
