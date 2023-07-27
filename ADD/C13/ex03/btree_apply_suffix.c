#include "ft_btree.h"

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root->left)
        btree_apply_suffix(root->left, (*applyf));
    (*applyf)(root->item);
    if (root->right)
        btree_apply_suffix(root->right, (*applyf));
}