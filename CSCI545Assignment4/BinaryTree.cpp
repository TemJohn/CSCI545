// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BinaryTree.h"
using namespace std;

/*
int _tmain(int argc, _TCHAR* argv[])
{
	BinaryTree<char> bt;

	bt.Insert('A', bt.rootNode);
	bt.Insert('B', bt.leftChild);
	bt.Insert('C', bt.rightChild);

	bt.moveTo(bt.leftChild);
	bt.Insert('D', bt.leftChild);
	bt.moveTo(bt.leftChild);

	bt.Insert('F', bt.rightChild);

	bt.moveTo(bt.rootNode);
	bt.moveTo(bt.rightChild);
	bt.Insert('E', bt.rightChild);
	bt.moveTo(bt.rightChild);

	bt.Insert('G', bt.leftChild);
	bt.moveTo(bt.rootNode);

	cout << "Size: " << bt.getSize() << endl;

	cout << "Preorder Traversal" << endl;
	bt.preOrder(bt.getRoot());
	cout << endl << endl;

	cout << "Inorder Traversal" << endl;
	bt.inOrder(bt.getRoot());
	cout << endl << endl;

	cout << "Postorder Traversal" << endl;
	bt.postOrder(bt.getRoot());
	cout << endl << endl;

	bt.moveTo(bt.rootNode);
	bt.moveTo(bt.rightChild);

	cout << "Current = " << bt.getCurrentElement() << endl;

	cout << "Find Parent of " << bt.getCurrentElement() << endl;
	bt.moveTo(bt.parentNode);
	cout << "Parent is: " << bt.getCurrentElement() << endl;

	cout << "Destroy the tree" << endl; 
	bt.Destroy(bt.getRoot());

	cout << "Size: " << bt.getSize() << endl;		
	system("pause");
	return 0;
}

*/