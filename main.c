#include <stdio.h>
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
    char descricao[200];
    int andamento;
} Tarefa;

int main() {
    int numero;

    printf("Digite um número de 1 a 7: ");
    scanf("%d", &numero);

    //Estrutura básica do documento

    switch(numero) {
        case 1: //(Daniel)
            printf("1. Inserir nova tarefa;\n");
            break;

        case 2: //(Gustavo)
            printf("Mostrar tarefas cadastradas;\n");
            break;

        case 3: //(João)
            printf("Buscar por tarefa;\n");
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
            printf("Comando inválido\n");
    }

    return 0;
}