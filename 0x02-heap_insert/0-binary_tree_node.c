#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->n = value;
	new_node->parent = parent;

	return (new_node);
}

/**
 * binary_tree_expected_nodes - return the height of a node
 * @tree_height: pointer to binary tree
 *
 * Return: return the height of a node
 */
size_t binary_tree_expected_nodes(size_t tree_height)
{
	size_t i, expected_nodes;

	expected_nodes = 0;
	for (i = 0; i <= tree_height; i++)
	{
		expected_nodes =  _pow_recursion(2, i) + expected_nodes;
	}

	return (expected_nodes);
}

/**
 *_pow_recursion - returns the value of x raised to the power of y.
 *@x: number raised.
 *@y: number power.
 *
 *Return: the result pow. If the number is less that 0, return -1.
 **/
int _pow_recursion(int x, int y)
{
	int rs = 0;

	if (y == 0)
	{
		rs = 1;
	}
	if (y == 1)
	{
		rs = x;
	}
	if (y < 0)
	{
		rs = -1;
	}
	if (y > 1)
	{
		rs = x * _pow_recursion(x, y - 1);
	}
	return (rs);
}

/**
 * binary_tree_height - return the height of a node
 * @tree: pointer to binary tree
 *
 * Return: return the height of a node
 */

size_t binary_tree_height(const heap_t *tree)
{

	int left = 0;
	int right = 0;

	if (!tree)
	{
		return (0);
	}
	else
	{
		if (tree->left)
			left = (1 + binary_tree_height(tree->left));
		if (tree->right)
			right = (1 + binary_tree_height(tree->right));

		if (left > right)
			return (left);
		else
			return (right);
	}
}

/**
 * binary_tree_size - return the size of a tree
 * @tree: pointer to binary tree
 *
 * Return: return the size of a node
 */

size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
