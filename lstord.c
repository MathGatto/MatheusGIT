#include "lstord.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lst_init(map_ptr_hash * l)
{
	*l = NULL;
}

int lst_size(map_ptr_hash l)
{
	int cont = 0;
	while (l != NULL) {
		cont++;
		l = l->prox;
	}
	return cont;
}

bool lst_isempty(map_ptr_hash l)
{
	return l == NULL;
}

void lst_ins(map_ptr_hash * l, map_key_hash key, map_value_hash val)
{
	map_ptr_hash n;
	if (*l == NULL || strcmp(key, (*l)->key) < 0) {
		if ((n = (map_ptr_hash) malloc(sizeof(struct map_node_hash))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		strcpy(n->key, key);
		if ((n->value = (map_value_hash *) malloc(sizeof(map_value_hash))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		*(n->value) = val;
		n->prox = *l;
		*l = n;
	}
	else {
		map_ptr_hash p = *l;
		while (p->prox != NULL && strcmp(p->prox->key, key) < 0)
			p = p->prox;
		if (strcmp(p->key, key) != 0 && (p->prox == NULL || strcmp(p->prox->key, key) != 0)) {
			if ((n = (map_ptr_hash) malloc(sizeof(struct map_node_hash))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			strcpy(n->key, key);
			if ((n->value = (map_value_hash *) malloc(sizeof(map_value_hash))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			*(n->value) = val;
			n->prox = p->prox;
			p->prox = n;
		}
		else { // já existe na lista, atualiza seu valor
			*((*l)->value) = val;
		}
	}
}

void lst_print(map_ptr_hash l)
{
	while (l != NULL) {
		printf("Codigo: %d  || Nome: %s   ||  Cobertura Vacinal:  %lf ", atoi(l->key), l->value->nome_municipio, l->value->cobertura_vacinal);
		l = l->prox;
	}
}

map_value_hash * lst_rem(map_ptr_hash * l, map_key_hash key)
{
	if (*l == NULL || strcmp(key, (*l)->key) < 0) {
		return NULL;
	}
	if (strcmp(key, (*l)->key) == 0) {
		map_ptr_hash p = *l;
		map_value_hash * val = (*l)->value;
		*l = (*l)->prox;
		free(p);
		return val;
	}
	map_ptr_hash p = *l;
	while (p->prox != NULL && strcmp(p->prox->key, key) < 0) {
		p = p->prox;
	}
	if (p->prox != NULL && strcmp(p->prox->key, key) == 0) {
		map_ptr_hash n = p->prox;
		map_value_hash * val = p->prox->value;
		p->prox = n->prox;
		free(n);
		return val;
	}
	return NULL;
}

map_value_hash * lst_find(map_ptr_hash l, map_key_hash key)
{
	if (l == NULL || strcmp(key, l->key) < 0) {
		return NULL;
	}
	if (strcmp(key, l->key) == 0) {
		return l->value;
	}
	while (l != NULL && strcmp(l->key, key) < 0) {
		l = l->prox;
	}
	if (l != NULL && strcmp(l->key, key) == 0) {
		return l->value;
	}
	return NULL;
}

//void lst_kill(map_ptr_hash * l)
//{
//	map_ptr_hash p;
//	while (*l != NULL)	{
//		p = *l;
//		*l = p->prox;
//		free(p);
//	}
//}
