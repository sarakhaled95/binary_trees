#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = binary_tree_size(tree->left);
		r = binary_tree_size(tree->right);
		return (1 + l + r);
	}
	return (0);

}
