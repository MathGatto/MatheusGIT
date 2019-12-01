#include "Hash_Map.h"
#include "lstord.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void map_init_hash(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) {
		lst_init(&m[i]);
	}
}

int map_size_hash(hash_map m)
{
	int i, cont = 0;
	for (i = 0; i < M; i++) {
		cont += lst_size(m[i]);
	}
	return cont;
}

bool map_isempty_hash(hash_map m)
{
	int i;
	for (i = 0; i < M; i++)
		if (!lst_isempty(m[i]))
			return false;
	return true;
}

map_value_hash * map_get_hash(hash_map m, map_key_hash key)
{
	return lst_find(m[h(key)], key);
}

void map_put_hash(hash_map m, map_key_hash key, map_value_hash val)
{
	lst_ins(&m[h(key)], key, val);
}

map_value_hash * map_remove_hash(hash_map m, map_key_hash key)
{
	return lst_rem(&m[h(key)], key);
}

/* método do meio do quadrado para chaves alfanuméricas */
int h(map_key_hash key)
{
	int i, soma = 0;
	// converte a chave para um inteiro
	for (i = 0; key[i] != '\0'; i++) {
		soma += key[i] << (i % 8);
	}

	// meio do quadrado
	soma *= soma;
	int x = log10(M) / log10(2);
	int desl = (NUM_BITS - x) / 2;
	soma >>= desl;
	return soma & ((int) pow(2, x) - 1);
}

void map_print_hash(hash_map m)
{
	int i;
	for (i = 0; i < M; i++) {
		printf("\n[%d] = ", i);
		printf("%d", lst_size(m[i]));
		lst_print(m[i]);
	}
	printf("\n");
}

