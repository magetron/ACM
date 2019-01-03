#include "stdio.h"
#include "stdlib.h"

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
	int height;
} node;

int max (int a, int b) {
	return a > b ? a : b;
}

int height (node *root) {
	return (root == NULL) ? 0 : root -> height;
}

node *new_node (int key) {
	node *tmp_node;
	tmp_node -> key = key;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	tmp_node -> height = 1;
	return tmp_node;
}

node *right_rotate (node *y) {
	node *x = y -> left;
	node *T2 = x -> right;

	x -> right = y;
	y -> left = T2;

	y -> height = max( height(y -> left), height(y -> right) ) + 1;
	x -> height = max( height(x -> left), height(x -> right) ) + 1;

	return x;
}

node *left_rotate (node *x) {
	node *y = x -> right;
	node *T2 = y -> left;

	y -> left = x;
	x -> right = T2;

	x -> height = max( height(x -> left), height(x -> right) ) + 1;
	y -> height = max( height(y -> left), height(y -> right) ) + 1;
	
	return y;
}

int get_balance_factor (node *root) {
	if (root == NULL) return 0;
	else return height(root -> left) - height(root -> right);
}

node *insert(node *root, int key) {
	// std bst insertion
	if (root == NULL) return new_node(key);
	if (key < root -> key) root -> left = insert(root -> left, key);
	else if (key > root -> key) root -> right = insert(root -> right, key);
	else return root;

	root -> height = max( height(root -> left), height(root -> right) ) + 1;

	int balance = get_balance_factor(root);

	// 4 cases for unbalanced node
	if ( (balance > 1) && (key < root -> left -> key) ) return right_rotate(root);

	if ( (balance < -1) && (key > root -> right -> key) ) return left_rotate(root);

	if ( (balance > 1) && (key > root -> left -> key) ) {
		root -> left = left_rotate(root -> left);
		return right_rotate(root);
	}

	if ( (balance < -1) && (key < root -> right -> key) ) {
		root -> right = right_rotate(root -> right);
		return left_rotate(root);
	}

	return root;
}

int find_by_key (node *root, int key) {
	if (root -> key == key) return count;


int main () {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		short int op;
		int num;
		scanf("%d%d", &op, &num);
		if (op == 1) insert(num);

	return 0;
}

