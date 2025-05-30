#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @note Árvore de decisão é uma árvore que carrega perguntas e respostas.
 * Aplicada a um contexto real, ela debate cada pergunta e dependendo da resposta vai para uma nova pergunta
 * ou um resultado final
 * 
 * @param No com filhos = Pergunta a ser refletida e leva para o sim ou não.
 * @param No folha = Resultado final da reflexão gerada.
 * 
 * @note A decisão da árvore consiste no resultado final advindo das perguntas feitas. A árvore aqui é um diagnóstico médico.
*/


/** @brief Estrutura de um nó da árvore de decisão.
    @details Contém o texto da pergunta ou diagnóstico, e os ponteiros para as respostas "sim" e "não". */
typedef struct No {
    char texto[100]; 
    struct No* sim;  
    struct No* nao;
} No;

/**
 * @brief Cria um novo nó da árvore de decisão.
 * 
 * @param texto Texto da pergunta ou diagnóstico.
 * @return Ponteiro para o nó recém-criado.
 * 
 * @note A função utiliza malloc. É necessário liberar a memória depois.
 */
No* criarNo(char texto[]) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->texto, texto);
    novo->sim = NULL;
    novo->nao = NULL;
    return novo;
}

/**
 * @brief Percorre a árvore de decisão conforme as respostas do usuário.
 * 
 * @param no Ponteiro para o nó atual.
 * 
 * @note A função faz perguntas até encontrar um nó folha, que contém o diagnóstico.
 */
void percorrerArvore(No* no) {
    if (no->sim == NULL && no->nao == NULL) {
        printf("Diagnóstico: %s\n", no->texto);
        return;
    }

    char resposta;
    printf("%s (s/n): ", no->texto);
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        percorrerArvore(no->sim);
    } else {
        percorrerArvore(no->nao);
    }
}

/**
 * @brief Desenha a estrutura da árvore no terminal.
 * 
 * @param no Ponteiro para o nó atual.
 * @param nivel Nível de profundidade na árvore, usado para calcular a indentação.
 * 
 * @note A visualização ajuda a entender a estrutura lógica da árvore.
 */
void desenharArvore(No* no, int nivel) {
    for (int i = 0; i < nivel; i++) {
        printf("   ");  // Espaçamento proporcional ao nível.
    }
    printf("-> %s\n", no->texto);

    if (no->sim != NULL) {
        desenharArvore(no->sim, nivel + 1);
    }
    if (no->nao != NULL) {
        desenharArvore(no->nao, nivel + 1);
    }
}

/**
 * 
 * @note A função monta a árvore, desenha sua estrutura, executa o diagnóstico e libera a memória.
 */
int main() {
    // Diagnósticos finais
    No* inf_viral_exant = criarNo("Infecção viral com exantema (ex.: sarampo)");
    No* inf_bacteriana = criarNo("Infecção bacteriana (ex.: amigdalite)");
    No* inf_respiratoria = criarNo("Infecção respiratória (ex.: bronquite)");
    No* virose_comum = criarNo("Virose comum");
    No* alergia_cutanea = criarNo("Alergia cutânea");
    No* alergia_leve = criarNo("Alergia leve");
    No* saudavel = criarNo("Saudável");

    // Sub-perguntas
    No* manchas = criarNo("Está com manchas no corpo?");
    manchas->sim = inf_viral_exant;
    manchas->nao = inf_bacteriana;

    No* tosse = criarNo("Tem tosse?");
    tosse->sim = inf_respiratoria;
    tosse->nao = virose_comum;

    No* dor_garganta = criarNo("Tem dor de garganta?");
    dor_garganta->sim = manchas;
    dor_garganta->nao = tosse;

    No* vermelhidao = criarNo("Está com vermelhidão na pele?");
    vermelhidao->sim = alergia_cutanea;
    vermelhidao->nao = alergia_leve;

    No* coceira = criarNo("Tem coceira?");
    coceira->sim = vermelhidao;
    coceira->nao = saudavel;

    // Raiz da árvore
    No* febre = criarNo("Tem febre?");
    febre->sim = dor_garganta;
    febre->nao = coceira;

    // Desenha a árvore
    printf("\n=== Estrutura da Árvore de Decisão ===\n");
    desenharArvore(febre, 0);

    // Executa o diagnóstico
    printf("\n=== Sistema de Diagnóstico Médico ===\n");
    percorrerArvore(febre);

    // Libera a memória alocada
    free(inf_viral_exant);
    free(inf_bacteriana);
    free(inf_respiratoria);
    free(virose_comum);
    free(alergia_cutanea);
    free(alergia_leve);
    free(saudavel);
    free(manchas);
    free(tosse);
    free(dor_garganta);
    free(vermelhidao);
    free(coceira);
    free(febre);

    return 0;
}
