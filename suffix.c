// ------------------------------------------------------------
//  Trabalho Estrutura de Dados II - Árvore de Sufixo
//		Ciênia da Computação
//
//	Aluno: Marlon da Silva Dias
//	GitHub: https://github.com/marlonsd/EDII-SuffixTree
//	suffix.c
//
// 0 = false; 1 = true;
// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include "suffix.h"

int insertSuffix(node *T, char *word){
	int aux, i, j, k, size;
	char *palavra;
	
	size = lenght(word);
	
	if (!(palavra = malloc(sizeof(char)*(size + 1)))){
		return 0;
	}
	
	for (i = 0; i < size; i++){
		j = size - i - 1;
		k = 0;
		while(j < size){
			palavra[k] = word[j];
			k++;
			j++;
		}
		palavra[k] = '\0';
		
		printf("%s\n", palavra);
		
		aux = insert(T, palavra);
		
		if (!aux){
			return 0;
		}	
	}
	
	printf("%x\n", T->key[2]);
	
	printSuffix(T);
	
	return 1;
}

char *largestPalindrome(node *T, char *word, int size){
	int i, j, k, pos;
	char *largest, *aux_largest;
	node *pointer, *aux;
	
	if (!(largest = malloc(sizeof(char)*size))){
		prinft("Falta de memória");
		exit(1);
	}
	
	if (!(aux_largest = malloc(sizeof(char)*size))){
		prinft("Falta de memória");
		exit(1);
	}
	
	largest[0] = '\0';
	
	pointer = T;
	for (i = 0; i < size; i++){
		aux = T;
		pos = position(word[i]);
		j = 0;
		k = i;
		while(aux->key[pos]){
			aux_largest[j] = word[k];
			j++;
			k++;
			aux = aux->key[pos];
			pos = position(word[k]);
		}
		aux_largest[j] = '\0';
		if (lenght(aux_largest) > lenght(largest)){
			copy(largest, aux_largest); // largest = aux_largest
		}
		
/*		if (word[i] == aux->character){
			
		}*/
	}
	
	printf("%s\n", larges)
}

int lenght(char *word){
	int i;
	
	for (i = 0; word[i] != '\0'; i++);
	
	return i;
}

void printSuffix(node *T){
	int i, j;
	node *aux;
	char *palavra, c;
	
	aux = T;
	
	if (!(palavra = malloc(sizeof(char)))){
		printf("Faltou memória.\n");
		exit(1);
	}
	
	j = 0;
	
	printf("%x\n", aux->key[0]);
	
	while (aux->kids){
		i = 0;

		while(!aux->key[i]){
			i++;
		}
		
		switch(i){
			case 0: c = 'A';
				break;
			case 1: c = 'C';
				break;
			case 2: c = 'G';
				break;
			case 3: c = 'T';
				break;
		}

		printf("%c\n", c);
		realloc(palavra, j);
		palavra[j] = i + 'A';

		aux = aux->key[i];
		
		j++;
	}	
}

void copy(char *word, char *other_word){
	int i, size;
	
	size = lenght(other_word);
	
	for (i = 0; i < size; i++){
		word[i] = other_word[i];
	}
}
