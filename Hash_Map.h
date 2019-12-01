#ifndef _HASH_MAP_H
#define _HASH_MAP_H

#define M 5570 // número de encaixes da tabela de hashing
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

/* função que inicializa o hash map */
void map_init_hash(hash_map);

/* função que devolve o número de elementos do hash mapa */
int map_size_hash(hash_map);

/* função que devolve verdadeiro se o hash map estiver vazio */
bool map_isempty_hash(hash_map);

/* função que devolve o endereço do valor associado a chave no mapa,
   caso a chave esteja contida no mapa, ou NULL, caso contrário */
map_value_hash * map_get_hash(hash_map, map_key_hash);

/* função que insere a entrada (chave, valor) no mapa se mapa não possuir
   um entrada para a chave */
void map_put_hash(hash_map, map_key_hash, map_value_hash);

/* função que remove a entrada (chave, valor) do mapa e devolve o endereço
   do valor, caso a chave esteja contido no mapa, ou NULL, caso contrário */
map_value_hash * map_remove_hash(hash_map, map_key_hash);

/* função de hashing que utiliza o método do meio do quadrado */
int h(map_key_hash);

/* função que imprime todas as entradas do hash map */
void map_print(hash_map);

#endif
