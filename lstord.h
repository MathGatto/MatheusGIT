#ifndef _LSTORD_H
#define _LSTORD_H

#include "Hash_Map.h"
#include <stdbool.h>

/* fun��o que inicializa a lista encadeada ordenada */
void lst_init(map_ptr_hash *);

/* fun��o que devolve o n�mero de elementos da lista */
int lst_size(map_ptr_hash);

/* fun��o que devolve verdadeiro se a lista estiver vazia */
bool lst_isempty(map_ptr_hash);

/* fun��o que insere um novo par (chave, valor) na lista */
void lst_ins(map_ptr_hash *, map_key_hash, map_value_hash);

/* fun��o que imprime a lista */
void lst_print(map_ptr_hash);

/* fun��o que remove a entrada (chave, valor) e devolve o
   endere�o do valor, caso sua chave esteja na lista, ou NULL,
   caso contr�rio */
map_value_hash * lst_rem(map_ptr_hash *, map_key_hash);

/* fun��o que e devolve o endere�o do valor, caso sua chave
   esteja na lista, ou NULL, caso contr�rio */
map_value_hash * lst_find(map_ptr_hash, map_key_hash);

/* fun��o que desaloca a lista */
//void lst_kill(map_ptr_hash *);

#endif
