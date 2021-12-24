#include "binary_trees.h"
#include <stdio.h>
/**
 * heap_insert - creates a binary tree node
 * @root: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{heap_t *new_node, *inserted_node;
	size_t tree_height, tree_size, expected_nodes, expected_leaves,
	expected_later_nodes, current_leaves_last_level, removed_root = 0;

	new_node = heap_tree_node();
	if (!new_node)
		return (NULL);
	if (*root == NULL)
	{new_node->n = value;
		inserted_node = *root = new_node;
	} else
	{tree_height = binary_tree_height(*root);
		tree_size = binary_tree_size(*root);
		expected_nodes = binary_tree_expected_nodes(tree_height);
		expected_leaves = _pow_recursion(2, tree_height);
		if (value > (*root)->n)
			update_root(root, &new_node, &inserted_node, &value, &removed_root);
		if (expected_nodes - tree_size == 0)
		{
			insert_node(-1, &*root, &new_node, &inserted_node, value, removed_root);
		} else
		{expected_later_nodes = binary_tree_expected_nodes(tree_height - 1);
			current_leaves_last_level = tree_size - expected_later_nodes;
			if (current_leaves_last_level < (expected_leaves / 2))
				insert_node(-1, &*root, &new_node, &inserted_node, value, removed_root);
			else
				insert_node(1, &*root, &new_node, &inserted_node, value, removed_root);
		}
	}
	return (removed_root ? *root : inserted_node);
}

/**
 * heap_tree_node - creates a binary tree node
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */
heap_t *heap_tree_node()
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);
	new_node->left = new_node->right = new_node->parent = NULL;

	return (new_node);
}

/**
 * update_root - creates a binary tree node
 * @root: pointer to the parent node of the node to create.
 * @new_node: value to put in the new node.
 * @inserted_node: value to put in the new node.
 * @value: value to put in the new node.
 * @removed_root: value to put in the new node.
 * Return: return a pointer to the new node, or NULL on failure.
 */
void update_root(heap_t **root, heap_t **new_node, heap_t **inserted_node,
int *value, size_t *removed_root)
{
	heap_t *temp;

	(*new_node)->left = (*root)->left;
	(*new_node)->right = (*root)->right;
	(*new_node)->parent = (*root)->parent;
	if ((*root)->left)
		(*root)->left->parent = *new_node;
	if ((*root)->right)
		(*root)->right->parent = *new_node;
	(*new_node)->n = *value;
	*value = (*root)->n;
	temp = *root;
	*root = *new_node;
	*inserted_node = *root;
	*new_node = temp;
	(*new_node)->left = NULL;
	(*new_node)->right = NULL;
	(*new_node)->parent = NULL;
	*removed_root = 1;
}

/**
 * insert_node - creates a binary tree node
 * @direction: pointer to the parent node of the node to create.
 * @root: pointer to the parent node of the node to create.
 * @new_node: value to put in the new node.
 * @inserted_node: value to put in the new node.
 * @value: value to put in the new node.
 * @removed_root: value to put in the new node.
 *
 * Return: return a pointer to the new node, or NULL on failure.
 */

void insert_node(int direction, heap_t **root, heap_t **new_node,
heap_t **inserted_node, int value, size_t removed_root)
{
	if (direction == -1)
	{
		if ((*root)->left)
		{
			*inserted_node = heap_insert(&(*root)->left, value);
		} else
		{
			(*new_node)->n = value;
			(*new_node)->parent = *root;
			(*root)->left = *new_node;
			if (!removed_root)
				*inserted_node = *new_node;
		}
	} else
	{
		if ((*root)->right)
		{
			*inserted_node = heap_insert(&(*root)->right, value);
		} else
		{
			(*new_node)->n = value;
			(*new_node)->parent = *root;
			(*root)->right = *new_node;
			if (!removed_root)
				*inserted_node = *new_node;
		}
	}
}
