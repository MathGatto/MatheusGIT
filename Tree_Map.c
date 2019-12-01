#include "Tree_Map.h"
#include "avl.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void map_init_tree(tree_map * m)
{
	*m = NULL;
}

int map_size_tree(tree_map m)
{
	return avl_size(m);
}

bool map_isempty_tree(tree_map m)
{
	return avl_isempty(m);
}

map_value_tree * map_get_tree(tree_map m, map_key_tree key)
{
	return avl_find(m, key);
}

void map_put_tree(tree_map * m, map_key_tree key, map_value_tree val)
{
	bool h;
	search(m, key, val, &h);
}
