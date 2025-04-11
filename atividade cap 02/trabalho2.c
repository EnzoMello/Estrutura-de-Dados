#include<stdio.h>
#include<stdlib.h>

/*Isso significa que, a partir deste ponto, podemos usar "Itemp" no lugar de "char" em qualquer parte do código.*/
typedef char Itemp;

// Define a estrutura da pilha com seus atributos
typedef struct stack {
    int max;     // Capacidade máxima da pilha
    int top;     // Indica a posição do topo da pilha (-1 se vazia)
    Itemp *item; // Ponteiro para armazenar os elementos da pilha
} *Stack;

// Função para criar uma nova pilha com capacidade máxima especificada
Stack createStack(int max) {
    // Aloca memória para a estrutura da pilha
    Stack stack = malloc(sizeof(struct stack));

    if(stack) { // Verifica se a memória foi alocada com sucesso
        stack->top = -1; // Inicializa o topo como -1 (indicando pilha vazia)
        stack->max = max; // Define a capacidade máxima da pilha
        // Aloca memória para o vetor de itens baseado na capacidade máxima
        stack->item = malloc(max * sizeof(Itemp));
        return stack; // Retorna a pilha criada
    }

    // Caso a alocação falhe, exibe uma mensagem de erro
    printf("Failed to allocate memory");
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack stack) {
    return stack->top == -1; // Retorna 1 (verdadeiro) se o topo for -1, caso contrário, 0 (falso)
}


int isFull(Stack stack) {
    return stack->top == stack->max - 1;
}

// empilhar
void stack(Itemp value, Stack stack) {
    if(isFull(stack)) {
        printf("stack is full");
        abort();
    }

    stack->top++;
    stack->item[stack->top] = value;
}

// desempilhar
Itemp unstack(Stack stack) {
    if(isEmpty(stack)) {
        printf("stack is empty");
        abort();
    }

    Itemp lastItem = stack->item[stack->top];
    stack->top--;
    return lastItem;
}

void destroy(Stack *stack) {
    free((*stack)->item);
    free(*stack);
    *stack = NULL;
}

// Função principal
int main() {
    // Criação das pilhas
    Stack stack1 = createStack(100);
    Stack stack2 = createStack(100);
    Stack stack3 = createStack(100);

    // Leitura da frase
    char phrase[100];
    printf("\nEnter a phrase: ");
    gets(phrase);

    // Preenche a pilha stack1
    for (int i = 0; phrase[i] != '\0'; i++) {
        stack(phrase[i], stack1);
    }

    // Desempilha de stack1 para stack2, ignorando espaços
    while (!isEmpty(stack1)) {
        while (!isEmpty(stack1) && stack1->item[stack1->top] != ' ') {
            stack(unstack(stack1), stack2);
        }
        while (!isEmpty(stack2)) {
            stack(unstack(stack2), stack3);
        }
        if (!isEmpty(stack1)) {
            stack(unstack(stack1), stack3);
        }
    }

    // Exibe o conteúdo de stack3
    while (!isEmpty(stack3)) {
        printf("%c", unstack(stack3));
    }
    printf("\n");

    // Libera memória das pilhas
    destroy(&stack1);
    destroy(&stack2);
    destroy(&stack3);

    return 0;
}