#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PALAVRA 10000

void gerarPalavra(int tamanho, char *palavra);

FILE *fin;

int main(){
	char *palavra;
		
	if((fin = fopen( "in.txt", "w")) == NULL ) {
		printf("nao foi possivel criar o arquivo\n");
		exit(1);
	}

	if (!(palavra = malloc((MAX_PALAVRA + 1)*sizeof(char)))){
		printf("Nao consegui alocar o vetor.\n");
		exit(1);
	}
	
		
	gerarPalavra(MAX_PALAVRA, palavra);
	
	fprintf(fin,"%s\n", palavra);

	fclose(fin);
	
	return 0;
}

/* A = 0
 * C = 1
 * G = 2
 * T = 3 */
void gerarPalavra(int tamanho, char *palavra){
	int i;
	char aux;
	
	srand(time(NULL));

	for (i = 0; i < tamanho; i++){
		aux = rand() % 4;
		//aux = 0;
		if (!aux){
			palavra[i] = 'A';
		} else {
			if (aux == 1){
				palavra[i] = 'C';
			} else {
				if (aux == 2){
					palavra[i] = 'G';
				} else {
					palavra[i] = 'T';
				}
			}
		}
	}
	
	palavra[tamanho] = '\0';
}
