// ------------------------------------------------------------
//  Trabalho Estrutura de Dados II - Árvore de Sufixo
//		Ciênia da Computação
//
//	Aluno: Marlon da Silva Dias
//	GitHub: https://github.com/marlonsd/EDII-SuffixTree
//	trie.h
// ------------------------------------------------------------


#ifndef TRIE_H_
#define TRIE_H_

struct no {
	struct no *key[5];
	struct no *father;
	char kids;
};

typedef struct no node;

/* Inicialização */
node *Trie();

/* Tratar a árvore */
int insert(node *T, char *word);
int find(node *T, char *word);
int delete(node *T, char *word);
node *get(node *T, char *word);
int erase(node* aux);
int isEmpty (node *T);
void printTree(node* T);

/* Funções para tratamento dos caracteres */
int position(char c);
char letter(int pos);

#endif
