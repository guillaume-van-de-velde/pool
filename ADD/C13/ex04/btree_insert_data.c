#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
    t_btree *btree;

    if (!root)
        return ;
    if (!*root)
        return (*root = btree_create_node(item), (void)0);
    btree = *root;
    if ((*cmpf)(item, btree->item) < 0)
        btree_insert_data(&btree->left, item, (*cmpf));
    else
        btree_insert_data(&btree->right, item, (*cmpf));
}