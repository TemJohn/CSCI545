#pragma once

//#include "BinaryTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
class node
{
public:
	T el;
	node<T> *left;
	node<T> *right;
	node();
	node(const T &el);
	bool equal(const T &el);
};

template <class T>
node<T>::node()
{
	left = nullptr;
	right = nullptr;
}

template <class T>
node<T>::node(const T &el)
{
	this->el = el;
	left = nullptr;
	right = nullptr;
}

template <class T>
bool node<T>::equal(const T &el)
{
	return this.el == el;
}


template <class T>
class binarySearchTree
{
public:

	binarySearchTree();
	binarySearchTree(const T &el);
	void setCurrent(node<T> &n);
	node<T>* getCurrent();
	node<T>* getRoot();
	
	bool isempty();

	// Add element in order to tree
	void add(T el);
	node<T> find(T el);
	void destroy(node<T> *n);
	void preorder(node<T> *);
	void inorder(node<T> *);
	void postorder(node<T> *);

	int size();

private:
	// The number of nodes
	int sz;
	node<T> *current;
	node<T> *root;
};

#endif // !BINARYSEARCHTREE_H
