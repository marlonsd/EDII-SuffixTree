// ------------------------------------------------------------
//  Trabalho Estrutura de Dados II - Árvore de Sufixo
//		Ciênia da Computação
//
//	Aluno: Marlon da Silva Dias
//	GitHub: https://github.com/marlonsd/EDII-SuffixTree
//	suffix.h
// ------------------------------------------------------------


#ifndef SUFFIX_H_
#define SUFFIX_H_

#include "trie.h"

int insertSuffix(node *T, char *word);
void *largestPalindrome(node *T, char *word, int size, node *P);
int lenght(char *word);
void copy(char *word, char *other_word);
char *inverse(char *word);
int checkWords(char *word, char *other_word);

#endif
