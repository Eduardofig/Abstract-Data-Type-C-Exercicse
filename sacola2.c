/* Eduardo Figueiredo Freire Andrade N°Usp 11232820
Mudança de TAD Sacola2
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "sacola.h"
/*Construção do tipo peca que contem:
nome: nome da peça
quantidade: quantidade da determinada peça
*/
typedef struct peca PECA;
PECA *criarPeca(char);
struct peca{
    char nome;
    int quantidade;
};
/*Contrução do tipo sacola que contém:
elem: vetor de char de TAM_MAX
used: inteiro que armazena o número de char contidos em elem
*/
struct sacola{
    PECA* elem[TAM_MAX];
    int used;
};
/*
Função que cria uma peça com alocação dinâmica e determina a quantidade para 1, ja que sera adicionada uma peca
Retorna um ponteiro para a peça
*/
PECA *criarPeca(char n){
    PECA *p = (PECA *)malloc(sizeof(PECA));
    p->nome = n;
    p->quantidade = 1;
    return p;
}
/*
Criação da sacola com alocação dinâmica e inicialização do contador used
Retorna o ponteiro da sacola
*/

SACOLA *criar(){
    SACOLA *sac = (SACOLA *)malloc(sizeof(SACOLA));
    sac->used = 0;

    return sac;
}
/*
Limpeza do elemento sacola e desalocação seu ponteiro
*/
void limpar(SACOLA *sac){
    if(sac){
        free(sac);
    }
}
/*
A funcao verifica as pecas por nome
Se achar uma com nome correspondente, retorna a variavel quantidade da mesma peca, caso nao encontre, retorna 0
*/
int contar(SACOLA *sac, char c){
    for (int i = 0; i < sac->used; i++)
        if(sac->elem[i]->nome == c){
            return sac->elem[i]->quantidade;
        }
    return 0;
}
/*
Cria pecas e insere ponteiros para a estrutura peca no vetor sacola
Só insere se ainda possui espaço (verificação através do elemento used)
Primeira condicional verifica se existe pelo menos um elemento na sacola para nao quebrar o for
Caso a determinada peca a ser inserida ja exista, somente sera alterada a variavel quantidade da determinada peça
*/

void inserir(SACOLA *sac, char c){
    int flag = 0;
    if(sac && sac->used != TAM_MAX){
        if(sac->used != 0){
            for (int k = 0; k < sac->used; k++){
                if (c == sac->elem[k]->nome){
                    sac->elem[k]->quantidade++;
                    return;
                }
            }
            sac->elem[sac->used] = criarPeca(c);
            sac->used++;
            return;
        }else{
            sac->elem[sac->used] = criarPeca(c);
            sac->used++;
            return;
        }
    }else if(sac->used == TAM_MAX){
        for (int j = 0; j < sac->used; j++){
                if (c == sac->elem[j]->nome){
                    sac->elem[j]->quantidade++;
                    return;
                    }
                }
            }
    return;
}
