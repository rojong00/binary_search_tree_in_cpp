#include "bst.h"

int main(int argc, char* argv[]){
	BSTtree BST;
	cout<<"Let's start"<<endl;
	BST.addNode(3);
	BST.addNode(3);
	BST.addNode(4);
	BST.addNode(10);
	BST.addNode(8);
	BST.addNode(1);
	BST.addNode(1);
    BST.searchNode(3);
    BST.removeNode(3);
	BST.addNode(5);
	BST.addNode(2);
    BST.printRootNode();
    BST.getTreeGraph();
	BST.addNode(14);
	BST.addNode(11);
	BST.addNode(7);
    BST.getTreeGraph();

	return 0;
}
