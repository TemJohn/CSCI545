#include <iostream>
#include "binarySearchTree.h"

using namespace std;

/*
In this assignment, you will develop and implement a Binary Search Tree (BST) data structure of
your own design. The BST must be able to hold any data T (it must be a generic/template
class) and must implement the following functions/methods:
- Add(element)
- Find(element)
- Preorder(node)
- Inorder(node)
- Postorder(node)
- Size
The add function/method must add the element to the BST, unless the value already exists.
The find function/method must return the BST Node that contains the element;
otherwise null is returned.
The Preorder function/method performs a preorder traversal upon the BST starting at node.
The Inorder function/method performs an inorder traversal upon the BST starting at node.
The Postorder function/method performs a postorder traversal upon the BST starting at node.
The size method/function/property returns the size of the BST.
Write a program that demonstrates the use of each of the functions/methods listed above.
Use the following string data to test your BST class: A, B, C, D, E, F, and G.

Design ideas from Malik:
A BST (T) is either empty or
- T has a special node called root
- T has two sets of nodes, left subtree and right subtree
- The key in the root is larger than every node in the left subtree
- Left subtree and Right subtree are also Binary Search Trees

*/


template<class T>
binarySearchTree<T>::binarySearchTree()
{
	root = NULL;
	sz = 0;
}

template<class T>
binarySearchTree<T>::binarySearchTree(const T &el)
{
	root = node<T>(el);
	setCurrent(root);
	sz = 1;
}

template<class T>
void binarySearchTree<T>::setCurrent(node<T> &n)
{
	current = &n;
}

template<class T>
node<T>* binarySearchTree<T>::getCurrent()
{
	return current;
}

template<class T>
node<T>* binarySearchTree<T>::getRoot()
{
	return root;
}

template<class T>
bool binarySearchTree<T>::isempty()
{
	return root == NULL;
}

template <class T>
void binarySearchTree<T>::add(T el)
{
	// A temporary node to compare to
	node<T> *newNode = new node<T>(el);
	// Used to find null nodes
	node<T> *cur = root;
	// Will be the head node when null node cur is found
	node<T> *prev = nullptr;

	// Check if the tree contains any nodes
	if (isempty()) {
		root = newNode;
		setCurrent(*newNode);
		sz = 1;
		return;
	}
	// If a node with this same element already exists, destroy the
	// temporary node and exit this function
/*	if (find(el).equal(NULL)) {
		destroy(newNode);
		return;
	}
	*/
	// Have current point to a null node where if the new node is
	// less than the prev node it will be on the left, and if it
	// is greater than the prev node it will be on the right
	while (cur != nullptr)
	{
		prev = cur;
		if (cur->el > el) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	// With the null node found, set the new node to this point
	if (prev->el > el) {
		prev->left = newNode;
	}
	else {
		prev->right = newNode;
	}
	current = newNode;
	// Increase the number of nodes
	sz++;
}

template <class T>
void binarySearchTree<T>::destroy(node<T> *n)
{
	if (n != NULL)
	{
		destroy(n->left);
		destroy(n->right);
		n = NULL;
		sz--;
	}
}


template <class T>
node<T> binarySearchTree<T>::find(T pEl)
{
	bool isfound = false;
	node<T> *current;

	// Check if the tree contains no nodes
	if (isempty()) {
		return NULL;
	}

	// Begin searching at root
	current = root;
	while (current != NULL && !isfound)
	{
		if (current->el == pEl) {
			isfound = true;
		}
		else if (current->el > pEl) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return current;
}

template<class T>
void binarySearchTree<T>::preorder(node<T> *node)
{
	if (node != NULL)
	{
		cout << node->el << endl;
		preorder(node->left);
		preorder(node->right);
	}
}

template<class T>
void binarySearchTree<T>::inorder(node<T> *node)
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << node->el << endl;
		inorder(node->right);
	}
}

template<class T>
void binarySearchTree<T>::postorder(node<T> *node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->el << endl;
	}
}

template<class T>
int binarySearchTree<T>::size()
{
	return sz;
}


int main(int argc, char* argv[])
{
	binarySearchTree<char> bst;
	bst.add('j');
	bst.add('a');
	bst.add('x');
	bst.add('z');
	bst.add('m');
	bst.add('c');
	bst.inorder(bst.getRoot());
	cout << "NEXT" << endl;
	bst.preorder(bst.getRoot());
	cout << "NEXT" << endl;
	bst.postorder(bst.getRoot());
	system("pause");
	return 0;
}