#ifndef _HASH_MAP_H
#define _HASH_MAP_H

#define M 5570 // n�mero de encaixes da tabela de hashing
#define MAX_DEF_HASH 50
#define NUM_BITS 16
#include <stdbool.h>

typedef char map_key_hash[10];

typedef struct {
 char nome_municipio[MAX_DEF_HASH + 1];
 double cobertura_vacinal;
} map_value_hash;

typedef struct map_node_hash * map_ptr_hash;

struct map_node_hash {
 map_key_hash key;
 map_value_hash * value;
 map_ptr_hash prox;
};
typedef map_ptr_hash hash_map[M];

/* fun��o que inicializa o hash map */
void map_init_hash(hash_map);

/* fun��o que devolve o n�mero de elementos do hash mapa */
int map_size_hash(hash_map);

/* fun��o que devolve verdadeiro se o hash map estiver vazio */
bool map_isempty_hash(hash_map);

/* fun��o que devolve o endere�o do valor associado a chave no mapa,
   caso a chave esteja contida no mapa, ou NULL, caso contr�rio */
map_value_hash * map_get_hash(hash_map, map_key_hash);

/* fun��o que insere a entrada (chave, valor) no mapa se mapa n�o possuir
   um entrada para a chave */
void map_put_hash(hash_map, map_key_hash, map_value_hash);

/* fun��o que remove a entrada (chave, valor) do mapa e devolve o endere�o
   do valor, caso a chave esteja contido no mapa, ou NULL, caso contr�rio */
map_value_hash * map_remove_hash(hash_map, map_key_hash);

/* fun��o de hashing que utiliza o m�todo do meio do quadrado */
int h(map_key_hash);

/* fun��o que imprime todas as entradas do hash map */
void map_print(hash_map);

#endif
