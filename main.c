#include <stdio.h>
#include <string.h>

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

void inserirTarefa(Tarefa lista[], int totalTarefas) {
    printf("Digite o titulo da tarefa: ");
    scanf(" %[^\n]", lista[totalTarefas].titulo);
    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]", lista[totalTarefas].descricao);
    lista[totalTarefas].andamento = 0;
    (totalTarefas)++;
    printf("Tarefa cadastrada com sucesso!\n");
}

// Função para mostrar todas as tarefas cadastradas
void mostrarTarefas(Tarefa lista[], int totalTarefas) {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    } else {
        printf("Tarefas cadastradas:\n");
        for (int i = 0; i < totalTarefas; i++) {
            printf("Tarefa %d:\n", i + 1);
            printf("Titulo: %s\n", lista[i].titulo);
            printf("Descricao: %s\n", lista[i].descricao);
            printf("Status: %s\n", lista[i].andamento ? "Concluida" : "Nao concluida");
            printf("----------------------------------------\n");
        }
    }
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

int main() {
    int numero;
    Tarefa listaTarefas[] = {
        {0, "oi", "teste", "Pendente"},
        {1, "Oi2", "teste2", "Fazendo"},
        {2, "Oi3", "teste3", "Concluido"}
    };

    while(numero != 8){

        //Exibe menu inicial
        exibirMenu();
        
        printf("Digite um numero para realizar alguma acao: \n");
        scanf("%d", &numero);

        //Finalizar execucao do script
        if (numero == 8){
            printf("Programa sendo finalizado...\n");
            break;
        }

        //Estrutura basica do documento
        switch(numero) {
            case 1:
                printf("1. Inserir nova tarefa;\n");
                break;

            case 2: 
                printf("2. Mostrar tarefas cadastradas;\n");
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
                int respostaEdicao;
                int lengthEdicao = sizeof(listaTarefas) / sizeof(listaTarefas[0]);

                printf("Buscar por tarefa por titulo ou posicao?\n");
                printf("0 - Titulo\n");
                printf("1 - Posicao\n");
                scanf("%d",&respostaEdicao);

                if(resposta == 0){
                    char titulo[25];
                    printf("Qual o titulo da tarefa que você deseja buscar? ");
                    scanf("%s",&titulo);
                    buscarTarefaPorTitulo(listaTarefas, lengthEdicao, titulo);
                }
                
                else if(resposta == 1){
                    int posicao;
                    printf("Qual a posicao da tarefa que você deseja editar? ");
                    scanf("%d",&posicao);
                    printf("\n");
                    editarTarefaPosicao(listaTarefas, length, posicao);
                }

                else{
                    printf("Não existe nenhum titulo ou posicao com esse valor\n");
                }
                break;

            case 5:
                printf("Remover tarefa;\n");
                break;

            case 6:
                printf("Marcar conclusão de uma tarefa específica;\n");
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
