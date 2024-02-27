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

Node* BSTtree::findMin(Node* Node_)
{
    while (Node_->left != nullptr)
    {
        printf("node->left->value : %d", Node_->left->value);
        Node_ = Node_->left;
    }

    return Node_;
}

void BSTtree::removeNode(int _value){
	Node* tmp =	search(_value);
    if (tmp == nullptr)
    {
        printf("(remove) : there isn't %d, so can't remove it\n", _value);
        return;
    }

	Node* parentOfTarget = tmp->parent;
    
    if (tmp->left == nullptr && tmp->right == nullptr)
    {
        if (parentOfTarget == nullptr)
        {
            root = nullptr;
        }
        else if (parentOfTarget->left == tmp)
        {
            parentOfTarget->left = nullptr;
        }
        else
        {
            parentOfTarget->right = nullptr;
        }

        delete tmp;
    }
    else if (tmp->left == nullptr || tmp->right == nullptr)
    {
        Node* child = (tmp->left == nullptr)? tmp->right : tmp->left;

        if (parentOfTarget == nullptr)
        {
            root = child;
        }
        else if (parentOfTarget->left == tmp)
        {
            parentOfTarget->left = child;
            child->parent = parentOfTarget;
        }
        else
        {
            parentOfTarget->right = child;
            child->parent = parentOfTarget;
        }

        delete tmp;
    }
    else
    {
        Node* successor = findMin(tmp->right);
        int tmpVal = successor->value;
        removeNode(successor->value); 
        tmp->value = tmpVal;
        printf("(remove) : there was %d, so has removed it\n", _value);
        printf("\t");
        displayNode1();
    }
}

Node* BSTtree::search(int _value){
	if (root == nullptr) {
			cout << "It's Empty intree" <<endl;
			return nullptr;
	}
	
	Node* tmp = root;
    size_t chkExit = 0;
	while(true){
        if ( tmp == nullptr ) 
            break;

		if (tmp->value == _value)
        {
            chkExit = 1;
            break;
        }
        else if (tmp->value < _value){
				if (tmp->right == nullptr)	
                {
                    chkExit = 2;
                    break;
                }
				else tmp = tmp->right;
		}
        else if (tmp->value > _value){
				if (tmp->left == nullptr)	
                {
                    chkExit = 2;
                    break;
                }
				else tmp = tmp->left;
		}
        else
        {}

        if (chkExit != 0)
            break;
	}
    if (chkExit == 2)
        return nullptr;
    return tmp;
}

void BSTtree::searchNode(int value_)
{
    Node* tmp = search(value_);
    printf("(search) ");
    if ( tmp == nullptr )
        printf("there isn't '%d'!\n", value_);
    else
        printf("there is '%d'!\n", value_);
}

void BSTtree::getTreeGraph()
{
    int maxDepth = 0;
    Node* tmp = root;
    if (tmp == nullptr)
    {
        printf("it's empty tree\n");
        return;
    }

    vector<int> arrValue(30, -1);
    arrValue[0] = tmp->value;
    DFSrecurssive(tmp, arrValue, maxDepth, 1);
    // print vector
    printf("maxDepth : %d\n", maxDepth);
    int arrIdx = 1;
    int tmpDepth = maxDepth;
    while(tmpDepth > 0)
    {
        arrIdx *= 2;
        tmpDepth--;
    }

    for ( int i = 0 ; i < arrIdx ; i++)
        printf("%d ", arrValue[i]);
    int levelTok = 0;
    printf("hi");
    for ( int i = 0 ; i < arrIdx ; i++ )
    {
        printf("%d ", arrValue[i]);
        if (levelTok == 0)
        {
            printf("\n");
            levelTok = i;
            tmpDepth = 2;
        }
        else if (i == levelTok+levelTok)
        {
            printf("\n");
            levelTok = tmpDepth;
            tmpDepth *= 2;
        }
        else
        {}
    }
}

void BSTtree::DFSrecurssive(const Node* tmp, vector<int> &arr, int& maxDepth, int tmpDepth)
{
    int idx = getIndexInTree(tmpDepth);
    while (true)
    {
        if (arr[idx] != -1)
            idx++;
        else
            break;
    }

    if (tmp == nullptr)
    {
        arr[idx] = -2;
        return;
    }

    maxDepth = tmpDepth > maxDepth ? tmpDepth : maxDepth;
    arr[idx] = tmp->value;
    printf("__arr[idx] = %d\n", tmp->value);
    printf("__arr[idx] = %d\n", arr[idx]);

    DFSrecurssive(tmp->left, arr, maxDepth, tmpDepth+1);
    DFSrecurssive(tmp->right, arr,  maxDepth, tmpDepth+1);
}

int BSTtree::getIndexInTree(int tmpDepth)
{
    int temp = 1;
    int tempDepth = tmpDepth;
    if (tmpDepth == 1)
        return 0;

    while(tempDepth > 0)
    {
        temp *= 2;
        tempDepth--;
    }

    return temp-1;
}
