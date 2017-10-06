#include <iostream>
using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};

struct node* root = nullptr;

void insert_integer(struct node** tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);


int main() {



	node * treeroot = root;



	insert_integer(&treeroot, 5);
	insert_integer(&treeroot, 3);
	insert_integer(&treeroot, 1);
	insert_integer(&treeroot, 7);
	insert_integer(&treeroot, 2);

	print_tree(treeroot);

	terminate_tree(treeroot);

	int x;
	cin >> x;

	return 0;
}

void insert_integer(node ** tree, int value)
{


	//check to see if nodeEvaluating is not a root
	if (*tree == nullptr) {
		*tree = new node;
		//to access members of the double pointer, must dereference once
		(*tree)->value = value;
		(*tree)->left = nullptr;
		(*tree)->right = nullptr;
		return;
	}


	//if value is less than value of current node, push value down leftside, else push down righthandside
	if (value < (*tree)->value) {
		//check if there is a left node to nodeEvaluating
		if ((*tree)->left == nullptr) {
			//create a new node to the left of nodeEvaluating
			(*tree)->left = new node;
			(*tree)->left->value = value;
			(*tree)->left->left = nullptr;
			(*tree)->left->right = nullptr;
		}
		else {
			//recursively insert value to left of nodeEvaluating 
			insert_integer(&((*tree)->left), value);
		}
	}
	else {
		//check if there is a right node to nodeEvaluating
		if ((*tree)->right == nullptr) {
			//create a new node to the right of nodeEvaluating
			(*tree)->right = new node;
			(*tree)->right->value = value;
			(*tree)->right->left = nullptr;
			(*tree)->right->right = nullptr;
		}
		else {
			//recursively insert value to right of nodeEvaluating
			insert_integer(&((*tree)->left), value);
		}
	}
}

void print_tree(node * tree)
{
	if (tree != nullptr) {
		if (tree->left != nullptr) {
			print_tree(tree->left);

		}
		cout << tree->value;
		if (tree->right != nullptr) {
			print_tree(tree->right);
		}
	}
}

//recursively iterate through lefthandside of tree, deleting all nodes from bottom upwards
void terminate_tree(node* tree) {

	if (tree != nullptr) {
		if (tree->left != nullptr) {
			terminate_tree(tree->left);
		}

		if (tree->right != nullptr) {
			terminate_tree(tree->right);
		}
		delete tree;
		tree = nullptr;

	}
}