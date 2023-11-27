#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node
 * @value: value inside node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *result = malloc(sizeof(binary_tree_t));

	if (result != NULL)
	{
		result->parent = parent;
		result->n = value;
		result->left = NULL;
		result->right = NULL;
	}
	return (result);
}
