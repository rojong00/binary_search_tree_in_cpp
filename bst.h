#ifndef __BST_HPP__
#define __BST_HPP__

#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct Node{
	int value;
	Node* parent;
	Node* left;
	Node* right;
} Node;

class BSTtree{
public:
	BSTtree(){
		root = nullptr;
	};
	~BSTtree(){};

	void addNode(int _value);
	void removeNode(int _value);
	void displayNode1(); // show all Node<K>
    void searchNode(int value_);
    void printRootNode(){
        printf("root node : %d\n", root->value);
    }

private:
	Node* root;
	void displayNode2(Node* _Node);
	Node* search(int _value);
};

#endif
