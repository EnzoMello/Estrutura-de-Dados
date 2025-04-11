#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Define serve para definir constantes no meu código

// typedef serve para eu englobar o tipo da estrutura e seu nome em um apelido só
typedef struct{
    char itens[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p){
    p->topo = -1; // A função ele coloca um ponteiro para apontar para a variável Pilha e, por meio do operador ->, consigo acessar a variável topo, modificando-a
}

int pilhaVazia(Pilha *p){
    return p->topo == -1; // A função tem o mesmo esquema da função acima, porém a verificação ocorre por 1(true) ou 0(false)
}

int pilhaCheia(Pilha *p){
    return p->topo == MAX - 1; // Essa função indica se o topo é igual ao último índice
}

void empilha(Pilha *p, char c){
    if(!pilhaCheia(p)){
        p->itens[++(p->topo)] = c; // Essa função incrementa o valor c no índice de itens correspondente ao valor de topo
    }
    
}

char desempilha(Pilha *p){
    if(!pilhaVazia(p)){
        return p->itens[(p->topo)--]; // Se a pilha não está vazia, retorno itens com um valor decrementado
    } else{
        return '\0';}
}

void revertePalavra(char *palavra){
    Pilha pilha;
    inicializaPilha(&pilha);

    for(int i = 0; palavra != '\0'; i++){
        empilha(&pilha, palavra[i]);
    }

    int i = 0;
    while(!pilhaVazia(&pilha)){
        palavra[i++] = desempilha(&pilha);
    }
    palavra[i] = '\0'; // A função vai incrementar a pilha com cada índice em palavra e depois vai desempilhando cada elemento e adicionando no índice de palavra.
}

void processaFrase(char *frase){
    char palavra[MAX];
    int j = 0;

    for(int i = 0; ; i++){
        if (frase[i] != ' ' && frase[i] != '\0'){
            palavra[j++] = frase[i]; 
        }else{
            palavra[j] = '\0';
            revertePalavra(palavra);
            printf("%s", palavra);
            if(frase[i] == '\0'){
                printf(" ");
            }
            j = 0;
        }

        if(frase[j] = '\0'){
            break;
        }
    }
}

int main() {
    char frase[MAX];

    printf("Digite uma frase: ");
    fgets(frase, MAX, stdin);
    frase[strcspn(frase, "\n")] = '\0';

    printf("Frase com palavras invertidas: ");
    processaFrase(frase);

    return 0;
}

