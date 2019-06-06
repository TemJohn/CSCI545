#ifndef H_BinaryTreeType
#define H_BinaryTreeType

#include <iostream>
#include <stack>
using namespace std;

template <class Type>
class nodeType
{
public:
	Type el;
	nodeType<Type> *left;
	nodeType<Type> *right;
	nodeType();
	nodeType(const Type &el);
};

template <class Type>
nodeType<Type>::nodeType()
{
	left = NULL;
	right = NULL;
}

template <class Type>
nodeType<Type>::nodeType(const Type &el)
{
	this->el = el;
	right = NULL;
	left = NULL;
}


template <class Type>
class BinaryTree
{
private:
	nodeType<Type> *current;
	nodeType<Type> *root;
	int size;

public:

	enum Relative
	{
		leftChild, rightChild, parentNode, rootNode
	};

	BinaryTree();
	void Destroy(nodeType<Type> *n);
	bool isEmpty();
	bool isLeaf();
	int getSize();
	nodeType<Type>* getRoot();
	Type getCurrentElement();
	nodeType<Type>* findParent(nodeType<Type> *n);
	bool moveTo(Relative rel);
	void Update( Type* );
	bool Insert(Type value, Relative rel);
	bool Insert(nodeType<Type> *newNode, Relative rel);
	void inOrder(nodeType<Type> *);
	void postOrder(nodeType<Type> *);
	void preOrder(nodeType<Type> *);
};

template <class Type>
BinaryTree<Type>::BinaryTree() 
{
	root = NULL;
	current = NULL;
	size = 0;
}

template <class Type>
void BinaryTree<Type>::Destroy(nodeType<Type> *n) 
{
	if (n != NULL)
	{
		Destroy(n->left);
		Destroy(n->right);
		n = NULL;
		size--;
	}
}

template <class Type>
int BinaryTree<Type>::getSize() {
	return size;
}
template <class Type>
bool BinaryTree<Type>::isEmpty() {
	return root == NULL;
}

template <class Type>
bool BinaryTree<Type>::isLeaf() {
	bool isLeaf = false;

	isLeaf = (current->left == NULL && current->right == NULL);

	return isLeaf;
}

template <class Type>
Type BinaryTree<Type>::getCurrentElement() 
{
	return current->el;
}


template <class Type>
nodeType<Type>* BinaryTree<Type>::findParent(nodeType<Type> *n) 
{
	stack<nodeType<Type> *> s ;
	n = root;
	while ( (n->left != current) && (n->right != current) )
	{
		if (n->right != NULL)
			s.push(n->right);

		if (n->left != NULL)
			n = n->left;
		else
		{
			n = s.top();
			s.pop();
		}


	}
	s.empty();

	return n;
}

template <class Type>
bool BinaryTree<Type>::moveTo(Relative rel) {
	bool found = false;

	switch (rel)
	{
	case leftChild:
		if (current->left != NULL)
		{
			current = current->left;
			found = true;
		}
		break;
	case rightChild:
		if (current->right != NULL)
		{
			current = current->right;
			found = true;
		}
		break;
	case parentNode:
		if (current != root)
		{
			current = findParent(current);
			found = true;
		}
		break;
	case rootNode:
		if (root != NULL)
		{
			current = root;
			found = true;
		}
		break;
	} // end Switch relative

	return found;
}

template <class Type>
nodeType<Type>* BinaryTree<Type>::getRoot() {
	return root;
}

template <class Type>
void BinaryTree<Type>::Update(Type *el) {
	current->el = el;
}


template <class Type>
bool BinaryTree<Type>::Insert(Type value, Relative rel) {
	bool inserted = true;

	nodeType<Type> *node = new nodeType<Type>(value);

	if ((rel == leftChild && current->left != NULL)
		|| (rel == rightChild && current->right != NULL))
	{
		inserted = false;
	} else
	{

		switch (rel)
		{
		case leftChild:
			current->left = node;
			break;
		case rightChild:
			current->right = node;
			break;
		case rootNode:
			if (root == NULL)
				root = node;
			current = root;
			break;
		}
	}

	size++;

	return inserted;
}

template <class Type>
bool BinaryTree<Type>::Insert(nodeType<Type> *newNode, Relative rel) {
	bool inserted = true;

	nodeType<Type> *node = new nodeType<Type>(newNode->el);

	if ((rel == leftChild && current->left != NULL)
		|| (rel == rightChild && current->right != NULL))
	{
		inserted = false;
	} else
	{

		switch (rel)
		{
		case leftChild:
			current->left = node;
			break;
		case rightChild:
			current->right = node;
			break;
		case rootNode:
			if (root == NULL)
				root = node;
			current = root;
			break;
		}
	}

	size++;

	return inserted;
}

template <class Type>
void BinaryTree<Type>::inOrder(nodeType<Type> *p) {
	if (p != NULL)
	{
		inOrder(p->left);
		cout << p->el;
		inOrder(p->right);
	}
}

template <class Type>
void BinaryTree<Type>::preOrder(nodeType<Type> *p) {
	if (p != NULL)
	{
		cout << p->el;
		preOrder(p->left);
		preOrder(p->right);
	}
}

template <class Type>
void BinaryTree<Type>::postOrder(nodeType<Type> *p) {
	if (p != NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		cout << p->el;
	}
}

#endif
