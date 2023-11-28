#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the
 * number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_l = 0, leaves_r = 0;

	if (tree)
	{
		if (!tree->left && !tree->right)
			return (1);

		leaves_l = binary_tree_leaves(tree->left);
		leaves_r = binary_tree_leaves(tree->right);
		return (leaves_l + leaves_r);
	}
	return (0);
}
