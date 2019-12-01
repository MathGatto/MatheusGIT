#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hash_Map.c"
#include "Tree_Map.c"
#include "avl.c"
#include "lstord.c"
#define arqNome "cobertura_vacinal.csv"

typedef struct {
    int codigo;
    char nome[MAX_DEF_HASH + 1];
    double cv;
} conteudo;


int main(){
FILE * f;
conteudo c[5570];


if((f = fopen(arqNome, "r")) == NULL) {
		fprintf(stderr, "Erro de abertura do arquivo %s!\n", arqNome);
		return 1;
	}
//printf ("eae");
int i=0, j=0, s;

char * token, linha[121];


while(fgets(linha, 121, f) != NULL){
    token = strtok(linha, ";");
    c[i].codigo = atoi(token);
    token = strtok(NULL, ";");
    strcpy(c[i].nome, token);
    token = strtok(NULL, ";");
    c[i].cv = atof(token);
    printf ("%d ; %s ; %lf \n", c[i].codigo, c[i].nome, c[i].cv);
    i++;

}

fclose(f);

return 0;
}
