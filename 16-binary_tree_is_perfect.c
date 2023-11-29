#include "binary_trees.h"
/**
 * is_leaf - checks if a node is a leaf
 * @node: node in binary tree
 * Return: 1 if leaf 0 if not
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * depth - return depth of node
 * @tree: a pointer to a node of binary tree
 * Return: depth of node
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree->parent != NULL)
		return (1 + depth(tree->parent));
	return (0);
}

/**
 * get_leaf - return leaf of binary tree
 * @tree: a pointer to a node of binary tree
 * Return: a pointer to leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect - checks if binary tree is perfect
 * @tree: a pointer to a node of binary tree
 * @leaf_depth: depth of node
 * @level: level of node
 * Return: 1 if perfect 0 if not
 */
int is_perfect(const binary_tree_t *tree, size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, leaf_depth, level + 1) &&
		is_perfect(tree->left, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect(tree, depth(get_leaf(tree)), 0));
}
