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
		
		//printf("%s\n", palavra);
		
		aux = insert(T, palavra);
		
		if (!aux){
			return 0;
		}	
	}
	
//	printf("%x\n", T->key[2]);
	
//	printSuffix(T);
	
	return 1;
}

char *largestPalindrome(node *T, char *word, int size){
	int i, j, k, pos;
	char *largest, *aux_largest, *aux_word;
	node *pointer, *aux;
	
	if (!(largest = malloc(sizeof(char)*size))){
		printf("Falta de memória");
		exit(1);
	}
	
	if (!(aux_largest = malloc(sizeof(char)*size))){
		printf("Falta de memória");
		exit(1);
	}
	
	largest[0] = '\0';
	
	pointer = T;
	printf("\n%d\n", size);
	for (i = 0; i < size; i++){
		//printf("\n-- %d\n", i);
		aux = T;
		pos = position(word[i]);
		j = 0;
		k = i;
		//printf("%d ", j);

		while(aux->key[pos]){
			aux_largest[j] = word[k];
			j++;
			k++;
			aux = aux->key[pos];
			pos = position(word[k]);
		}
		
		aux_largest[j] = '\0';

		while (j > 0){
			if (!palindrome(aux_largest)){
				j--;
				aux_largest[j] = '\0';
			} else {
				break;
			}
		}
		
		if (j > 1){
			printf("%s\n", aux_largest);
		}
		
		if (lenght(aux_largest) > lenght(largest)){
			copy(largest, aux_largest); // largest = aux_largest
		}
	}
	
	printf("\n%s\n", largest);
}

int lenght(char *word){
	int i;
	
	for (i = 0; word[i] != '\0'; i++);
	
	return i;
}

void copy(char *word, char *other_word){ // word = other_word;
	int i, size;
	
	size = lenght(other_word);
	
	for (i = 0; i < size+1; i++){
		word[i] = other_word[i];
	}
}

char *inverse(char *word){
	int i, size;
	char *inverso;
	
	size = lenght(word);
	
	if (!(inverso = malloc(sizeof(char)*(size + 1)))){
		printf("Falta de memória.\n");
		exit(1);
	}
	
	for (i = 0; i < size; i++){
		inverso[i] = word[size-i-1];
	}
	
	return inverso;
}

int palindrome(char *word){
	int i, size;
	
	size = lenght(word);

//	printf("%s %s\n", word, other_word);
	size--;
	for (i = 0; i <= size/2; i++){
		if (word [i] != word [size - i]){
			return 0;
		}
	}
	
	return 1;
}
