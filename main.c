// ------------------------------------------------------------
//  Trabalho Estrutura de Dados II - Árvore de Sufixo
//		Ciênia da Computação
//
//	Aluno: Marlon da Silva Dias
//	GitHub: https://github.com/marlonsd/EDII-SuffixTree
//	main.c
// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "trie.h"	// Implementação das funções da trie
#include "suffix.h"

#define TAM 35000

int main(){
	unsigned long int i;
	int size;
	node *raiz;
	char aux, op, sel, *palavra, *inverso;
	
	raiz = Trie();
	
	if (!(palavra = malloc(sizeof(char)*(TAM + 1)))){
		printf("Falha a alocar memória.\n");
		exit(1);
	}

	i = 0;
	
	scanf("%c", &aux);
	while(aux != '\n'){
		palavra[i] = aux;
		i++;
		scanf("%c", &aux);
	}
	
	palavra[i] = '\0';
	
	op = insertSuffix(raiz, palavra);
	
	size = lenght(palavra);
	
	/*if (!(inverso = malloc(sizeof(char)*(size + 1)))){
		printf("Falta de memória.\n");
		exit(1);
	}
	
	for (i = 0; i < size; i++){
		inverso[i] = palavra[size-i-1];
	}*/
	
	inverso = inverse(palavra);
	
	printf("%s %s", palavra, inverso);
	
	free(palavra);
	
	palavra = largestPalindrome(raiz, inverso, size);
	
	if (op){
		printf("v");
	} else {
		printf("Falha ao gerar a árvore de sufixos");
	}
			
	return 0;
}
