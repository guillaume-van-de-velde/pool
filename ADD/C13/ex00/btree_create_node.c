#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *btree;

    btree = malloc(sizeof(t_btree));
    if (!btree)
        return (NULL);
    btree->item = item;
    btree->left = NULL;
    btree->right = NULL;
    return (btree);
}