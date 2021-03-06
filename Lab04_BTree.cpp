// Lab04_BTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

struct Node {
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * searchNode(Node * root, int value) {
	Node * rightResult;
	Node * leftResult;
	if (root == NULL) {
		return NULL;
	}
	else if (root->value == value) {
		return root;
	}
	else {
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL) {
			return NULL;
		}
		else if (rightResult != NULL) {
			return rightResult;
		}
		else {
			return leftResult;
		}
	}
}

void insertLeft(Node * Parent, Node * nodeToInsert) {
	if (Parent == NULL){
		cout << "parent == NULL  LN" << endl;
	}
	else {
		Parent->leftNode = nodeToInsert;
	}
}

void insertRight(Node * Parent, Node * nodeToInsert) {
	if (Parent == NULL) {
		cout << "parent == NULL  RN" << endl;
	}
	else {
		Parent->rightNode = nodeToInsert;
	}

}

void inOrderTransversal(Node * root) {
	if (root != NULL) {
		inOrderTransversal(root->leftNode);
		cout << root->value << endl;
		inOrderTransversal(root->rightNode);
	}
}

void postOrderTransversal(Node * root) {
	if (root != NULL) {
		postOrderTransversal(root->leftNode);
		postOrderTransversal(root->rightNode);
		cout << root->value << endl;
	}
}

void preOrderTransversal(Node * root) {
	if (root != NULL) {
		cout << root->value << endl;
		preOrderTransversal(root->leftNode);
		preOrderTransversal(root->rightNode);
	}
}


int main() {
	Node * BinaryTree = new Node;	//creating a new node named BinaryTree
	BinaryTree->value = 5;			//assigning the BinaryTree node value to 5
	Node * tmp = new Node;			//creating a tmp node
	tmp->value = 1;					//tmp val = 1
	BinaryTree->rightNode = tmp;	//BT node -> right = tmp (1)
	
	tmp = new Node;
	tmp->value = 4;
	BinaryTree->leftNode = tmp;
	
	tmp = new Node;
	tmp->value = 10;
	insertLeft((searchNode(BinaryTree, 4)), tmp);
	
	tmp = new Node;
	tmp->value = 15;
	insertRight((searchNode(BinaryTree, 4)), tmp);

	tmp = new Node;
	tmp->value = 8;
	insertLeft((searchNode(BinaryTree, 15)), tmp);

	tmp = new Node;
	tmp->value = 7;
	insertRight((searchNode(BinaryTree, 1)), tmp);

	tmp = new Node;
	tmp->value = 9;
	insertRight((searchNode(BinaryTree, 7)), tmp);

	cout << "inOrderTransversal: \n";
	inOrderTransversal(BinaryTree);
	cout << "\npostOrderTransversal: \n";
	postOrderTransversal(BinaryTree);
	cout << "\npreOrderTransversal: \n";
	preOrderTransversal(BinaryTree);
	Node * searchResult = searchNode(BinaryTree, 2);
	if (searchResult != NULL) {
		cout << searchResult << endl;
	}
	else {
		cout << "The node searched does not exist." << endl;
	}
}


