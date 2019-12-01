#ifndef _LSTORD_H
#define _LSTORD_H

#include "Hash_Map.h"
#include <stdbool.h>

/* função que inicializa a lista encadeada ordenada */
void lst_init(map_ptr_hash *);

/* função que devolve o número de elementos da lista */
int lst_size(map_ptr_hash);

/* função que devolve verdadeiro se a lista estiver vazia */
bool lst_isempty(map_ptr_hash);

/* função que insere um novo par (chave, valor) na lista */
void lst_ins(map_ptr_hash *, map_key_hash, map_value_hash);

/* função que imprime a lista */
void lst_print(map_ptr_hash);

/* função que remove a entrada (chave, valor) e devolve o
   endereço do valor, caso sua chave esteja na lista, ou NULL,
   caso contrário */
map_value_hash * lst_rem(map_ptr_hash *, map_key_hash);

/* função que e devolve o endereço do valor, caso sua chave
   esteja na lista, ou NULL, caso contrário */
map_value_hash * lst_find(map_ptr_hash, map_key_hash);

/* função que desaloca a lista */
//void lst_kill(map_ptr_hash *);

#endif
