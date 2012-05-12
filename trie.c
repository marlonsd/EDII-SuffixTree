// ------------------------------------------------------------
//  Trabalho Estrutura de Dados II - Árvore de Sufixo
//		Ciênia da Computação
//
//	Aluno: Marlon da Silva Dias
//	GitHub: https://github.com/marlonsd/EDII-SuffixTree
//	trie.c
//
// 0 = false; 1 = true;
// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

/* Cria um novo nodo;
 * Inicializa suas variáveis;
 * Poem o sinal indicar de fim de palavra em todas as letras do vetor. */
node *Trie(){
	node *T;
	int i;
	
	if (!(T = malloc(sizeof(node)))){
		return NULL;
	}
	
	T->father = NULL;
	
	for (i = 0; i < 5; i++){
		T->key[i] = NULL;
	}
	
	T->kids = 0;
	
	return T;
}

/* Insere um novo elemento na árvore */
int insert(node *T, char *word){
	int i, pos;
	node *aux, *pointer;
	
	pointer = T;

	for (i = 0; word[i] != '\0'; i++){
		pos = position(word[i]);
		if (pointer->key[pos]){
			pointer = pointer->key[pos];
		} else {
			aux = Trie();
			if (!aux) {
				return 0;
			}
			pointer->key[pos] = aux;
			aux->father = pointer;
			pointer->kids++;
			pointer = aux;
		}
	}
	
	if (!pointer->key[4]){
		pointer->key[4] = (node *) 1;
		pointer->kids++;
	}
	
	return 1;
	
}
/* Função auxiliar
 * Acha o final da palavram
 * Se for encontrado, retorna algum ponteiro; senão, null */
node *get(node *T, char *word){
	int i, pos;
	node *pointer;
	
	i = 0;

	pointer = T;
	if (word[i] == '\0'){
		return NULL;
	} else {
		while((word[i] != '\0') && (pointer)){
			pos = position(word[i]);
			pointer = pointer->key[pos];
			i++;
		}
	}
	
	return pointer;
}

/* Localiza um elemento na árvore */
int find(node *T, char *word){
	node *aux;
	
	aux = get(T, word);
	
	if (aux){
		return 1;
	}
	
	return 0;
}

/* Remove um elemento da árvore */
int delete(node *T, char *word){
	int i;
	node *aux, *father;
	
	aux = get(T, word);

	if (aux && aux->key[4]){
		aux->key[4] = NULL;
		aux->kids--;
			
		while (aux && (!aux->kids)){
			father = aux->father;
			i = 0;
			
			while((father->key[i] != aux) && (i < 4)){
				i++;
			}
			
			father->key[i] = NULL;
			
			if (aux->father){
				free(aux);
			}
			
			aux = father;
		}
	
	} else {
		return 0;
	}
	return 1;
}

/* Deletar a palavra a partir de dado nodo */
int erase (node* aux){
	int i;
	node *father;
	
	if (aux && aux->key[4]){
		aux->key[4] = NULL;
		aux->kids--;
		while (aux->father && (!aux->kids)){
			father = aux->father;
			i = 0;
			
			while((father->key[i] != aux) && (i < 4)){
				i++;
			}

			father->key[i] = NULL;
			father->kids--;
			
			if (aux->father){
				free(aux);
			}
			
			aux = father;
		}
	} else {
		return 0;
	}
	
	return 1;
}

int position(char c){
	int pos;
	
	switch(c){
		case 'A': pos = 0;
			break;
		case 'C': pos = 1;
			break;
		case 'G': pos = 2;
			break;
		case 'T': pos = 3;
			break;
	}
	
	return pos;
}

char letter(int pos){
	char letra;
	
	letra = '\0';
	
	switch(pos){
		case 0: letra = 'A';
			break;
		case 1: letra = 'C';
			break;
		case 2: letra = 'G';
			break;
		case 3: letra = 'T';
			break;
	}
	
	return letra;
}

int isEmpty (node *T){
	int i;
	i = 0;
	
	if (T->kids){
		while (!(T->key[i]) && (i < 5)){
			i++;
		}
		
		if (i <= 4){
			return 0;
		}
	}
	
	return 1;
}

void printTree(node* T, int size){
	int i, j;
	char *word;
	node *aux;
	
	if(!(word = malloc(sizeof(char)*size))){
		printf("Faltou memória.\n");
		exit(1);
	}
	
	while(!(isEmpty(T))){  // enquanto árvore não vazia
		aux = T;
		j = 0;
		while(!aux->key[4]){
			i = 0;
			
			while ((!aux->key[i]) && (i < 4)){
				i++;
			}
			
			word[j] = letter(i);
			aux = aux->key[i];
			j++;
		}
		word[j] = '\0';
		if (lenght(word) == size){
			printf("\n%s", word);
		}
		erase(aux);
	}
	printf("\n");
}

void emptyTree(node* T){
	int i, j;
	node *aux;
	
	while(!(isEmpty(T))){  // enquanto árvore não vazia
		aux = T;
		j = 0;
		while(!aux->key[4]){
			i = 0;
			
			while ((!aux->key[i]) && (i < 4)){
				i++;
			}
			
			aux = aux->key[i];
			j++;
		}
		erase(aux);
	}
}
