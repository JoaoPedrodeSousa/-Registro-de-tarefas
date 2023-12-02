#include <stdio.h>
#include <string.h>
// Crie um sistema que permita o cadastro de tarefas. O menu deve permitir as seguintes ações:
//  1. Inserir nova tarefa; (Daniel)
//  2. Mostrar tarefas cadastradas (Gustavo)
//  3. Buscar por tarefa; (João)
//  4. Editar informações de uma tarefa; (Erik)
//  5. Remover tarefa; (Viktor)
//  6. Marcar conclusão de uma tarefa específica; (Viktor)
//  7. Salvar lista de tarefas em um arquivo, incluindo se cada uma foi finalizada ou não (Erik)

// Separe 


typedef struct { // <----------------------- struct com as propriedades de cada tarefa
    int posicao;
    char titulo[25];
    char descricao[200];
    char estado[9]; //Pendente, Fazendo, Concluido

} Tarefa;


Tarefa buscarTarefaPorTitulo(Tarefa listaTarefas[], int length, char titulo[25]){

    for (int i=0;i<length;i++){
        if(strcmp(titulo, listaTarefas[i].titulo) == 0){
            printf("--------------------------------------------------------------\n");

            printf("Posicao: %d\n",listaTarefas[i].posicao);
            printf("Titulo: %s\n",listaTarefas[i].titulo);
            printf("Descricao: %s\n",listaTarefas[i].descricao);
            printf("estado: %s\n",listaTarefas[i].estado);
        
            printf("--------------------------------------------------------------\n");

            return listaTarefas[i];
        }
    }
    
}

Tarefa buscarTarefaPorPosicao(Tarefa listaTarefas[], int length, int posicao){

    for (int i=0;i<length;i++){
        if(posicao == listaTarefas[i].posicao){
            printf("--------------------------------------------------------------\n");

            printf("Posicao: %d\n",listaTarefas[i].posicao);
            printf("Titulo: %s\n",listaTarefas[i].titulo);
            printf("Descricao: %s\n",listaTarefas[i].descricao);
            printf("estado: %s\n",listaTarefas[i].estado);
        
            printf("--------------------------------------------------------------\n");
            
            return listaTarefas[i];
        }
    }
}

int main() {
    int numero;
    // Menu inicial
    printf("--------------------------------------------------------------\n");

    printf("1. Inserir nova tarefa.\n");
    printf("2. Mostrar tarefas cadastradas.\n");
    printf("3. Buscar por tarefa.\n");
    printf("4. Editar informações de uma tarefa.\n");
    printf("5. Remover tarefa.\n");
    printf("6. Marcar conclusao de uma tarefa especifica.\n");
    printf("7. Salvar lista de tarefas em um arquivo.\n\n");
    
    printf("--------------------------------------------------------------\n");

    Tarefa listaTarefas[] = {
        {0, "oi", "teste", "Pendente"},
        {1, "Oi2", "teste2", "Fazendo"},
        {2, "Oi3", "teste3", "Concluido"}
    };

    
    printf("Digite um número para realizar alguma ação: ");
    scanf("%d", &numero);

    //Estrutura básica do documento

    switch(numero) {
        case 1: //(Daniel)
            printf("1. Inserir nova tarefa;\n");
            break;

        case 2: //(Daniel)
            printf("2. Mostrar tarefas cadastradas;\n");
            break;

        case 3: //(João)
            int resposta;
            int length = sizeof(listaTarefas) / sizeof(listaTarefas[0]);

            printf("Buscar por tarefa por titulo ou posicao?\n");
            printf("0 - Titulo\n");
            printf("1 - Posicao\n");
            scanf("%d",&resposta);

            if(resposta == 0){
                char titulo[25];
                printf("Qual o titulo da tarefa que você deseja buscar? ");
                scanf("%s",&titulo);
                buscarTarefaPorTitulo(listaTarefas, length, titulo);
            }
            
            else if(resposta == 1){
                int posicao;
                printf("Qual a posicao da tarefa que você deseja buscar? ");
                scanf("%d",&posicao);
                printf("\n");
                buscarTarefaPorPosicao(listaTarefas, length, posicao);
            }

            else{
                printf("Não existe nenhum titulo ou posicao com esse valor\n");
            }

            break;

        case 4: //(Erik)
            printf("Editar informações de uma tarefa; \n");
            break;

        case 5: //(Viktor)
            printf("Remover tarefa;\n");
            break;

        case 6: //(Viktor)
            printf("Marcar conclusão de uma tarefa específica;\n");
            break;

        case 7: //(Erik)
            printf("Salvar lista de tarefas em um arquivo\n");
            break;

        default:
            printf("Número inválido, tente novamente! \n");
    }

    return 0;
}
