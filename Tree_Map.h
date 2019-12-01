#ifndef _TREE_MAP_H
#define _TREE_MAP_H

#define MAX_DEF_TREE 30
#define MAX_WORD 30
#include <stdbool.h>

typedef char map_key_tree[10];

typedef struct {
 char nome_municipio[MAX_DEF_TREE + 1];
 double cobertura_vacinal;
} map_value_tree;

typedef struct map_node_tree * map_ptr_tree;

struct map_node_tree {
 map_key_tree key;
 map_value_tree * value;
 map_ptr_tree esq;
 map_ptr_tree dir;
 int bal;
};
typedef map_ptr_tree tree_map;


/* função que inicializa o tree map */
void map_init_tree(tree_map *);

/* função que devolve o número de elementos do tree mapa */
int map_size_tree(tree_map);

/* função que devolve verdadeiro se o tree map estiver vazio */
bool map_isempty_tree(tree_map);

/* função que devolve o endereço do valor associado a chave no mapa,
   caso a chave esteja contida no mapa, ou NULL, caso contrário */
map_value_tree * map_get_tree(tree_map, map_key_tree);

/* função que insere a entrada (chave, valor) no mapa se mapa não possuir
   um entrada para a chave */
void map_put_tree(tree_map *, map_key_tree, map_value_tree);

#endif
