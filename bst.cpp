#include "bst.h"

void BSTtree::displayNode1(){
	if (root == nullptr){
			cout<<"it's empty tree"<<endl;
			return;
	}

	Node* tmp = root;
	displayNode2(tmp);
    cout << '\n';
}

void BSTtree::displayNode2(Node* _Node){
	if (_Node == nullptr) return;
	displayNode2(_Node->left);
	cout << _Node->value <<" ";
	displayNode2(_Node->right);
}

void BSTtree::addNode(int _value){
	Node* newNode = new Node;
	newNode->value = _value;
	newNode->parent = nullptr;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (root == nullptr){
			root = newNode;
            printf("(added Node : %d ) : ", _value);
            displayNode1();
			return;
	}
	Node* tmp = root;
    bool chkAdded = false;
	while(true){
			if (tmp->value == _value && chkAdded == false) {
					cout << "(already exists : " << _value << ") : ";
                    displayNode1();
                    delete newNode;
                    break;
			}

			while(tmp->value > _value){
					if ( tmp->left == NULL){
							newNode->parent = tmp;
							tmp->left = newNode;
                            chkAdded = true;
                            break;
					} else {
							tmp = tmp->left;
                            break;
					}
			}

			while (tmp->value < _value){
					if ( tmp->right == nullptr){
							newNode->parent= tmp;
							tmp->right = newNode;
                            chkAdded = true;
							break;
					} else {
							tmp = tmp->right;
                            break;
					}
			}

            if (chkAdded == true) 
            {
                printf("(added Node : %d ) : ", _value);
                displayNode1();
                break;
            }
	}
}

void BSTtree::removeNode(int _value){
	Node* tmp =	search(_value);
	Node* _parent = tmp->parent;
//	_parent->
}

Node* BSTtree::search(int _value){
	if (root == nullptr) {
			cout << "It's Empty intree" <<endl;
			return nullptr;
	}
	
	Node* tmp = root;
	while(true){
        if ( tmp == nullptr ) 
            break;

		if (tmp->value == _value)
            break;

		while (tmp->value > _value){
				if (tmp->left == nullptr)	
                    return nullptr;
				else tmp = tmp->left;
		}
		while (tmp->value > _value){
				if (tmp->right == nullptr)	
                    return nullptr;
				else tmp = tmp->right;
		}
	}
    return tmp;
}

void BSTtree::getTreeGraph()
{
	int Graph = 0;
	while (true)
		{
			break;
		}
}

void BSTtree::searchNode(int value_)
{
    Node* tmp = search(value_);
    if ( tmp == nullptr )
        printf("there isn't '%d'!\n", value_);
    else
        printf("there is '%d'!\n", value_);
}

