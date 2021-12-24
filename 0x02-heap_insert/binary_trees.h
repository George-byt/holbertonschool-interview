#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_height(const heap_t *tree);
size_t binary_tree_size(const heap_t *tree);
size_t binary_tree_expected_nodes(size_t tree_height);
int _pow_recursion(int x, int y);
heap_t *heap_tree_node();
void update_root(heap_t **root, heap_t **new_node, heap_t **inserted_node,
int *value, size_t *removed_root);
void insert_node(int direction, heap_t **root, heap_t **new_node,
heap_t **inserted_node, int value, size_t removed_root);

/*Functions printing*/
void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
