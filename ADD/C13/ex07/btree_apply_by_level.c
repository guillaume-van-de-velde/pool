#include "ft_btree.h"

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
    static int  level = -1;

    level++;
    if (!root)
        return ;
    (*applyf)(root->item, level, (level == 0));
    if (root->left)
        btree_apply_by_level(root->left, (*applyf));
    if (root->right)
        btree_apply_by_level(root->right, (*applyf));
    level--;
}