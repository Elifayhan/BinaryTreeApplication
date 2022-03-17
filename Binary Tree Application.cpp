#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insertElement(struct node *tree, int value) {
	struct node *ptr, *newNode, *parent;
	ptr = new struct node; //we have created space for the node we will create
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	if (tree == NULL)
	{
		tree = ptr;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		parent = NULL;
		newNode = tree;
		while (newNode != NULL)
		{
			parent = newNode;
			if (value < newNode->data)
				newNode = newNode->left;
			else
				newNode = newNode->right;
		}

			parent->left = ptr;
		else
			parent->right = ptr;
	}
	return tree;
}
void postorderTraversal(struct node *tree) {
	if (tree != NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		cout << tree->data;
	}
}
int main()
{
	struct node *tree;
	tree = NULL;
	int choose = 1;
	int number;
	while (choose != 0)
	{
		cout << "Enter the number that you want to add to the tree:";
		cin >> number;
		tree = insertElement(tree, number);
		cout << "Please press another number to continue to zero to exit:" << endl;
		cin >> choose;
	}
	cout << "Postorder Traversal:" << endl;
	postorderTraversal(tree);
}