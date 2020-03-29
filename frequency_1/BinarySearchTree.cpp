#include "BinarySearchTree.h"


BTree::BTree()
{
	this->key = -1;
	this->count = 0;
}

BTree::~BTree()
{

}

void BTree::PreOrder()
{
	if (this != NULL)
	{
		cout << "Key : " << this->key << "\t|\tFreq : " << this->count << endl;
		this->left->InOrder();
		this->right->InOrder();
	}
}
 
void BTree::InOrder()
{
	if (this != NULL)
	{
		this->left->InOrder();
		cout << "Key : " << this->key << "\t|\tFreq : " << this->count << endl;
		this->right->InOrder();
	}
}

void BTree::PostOrder()
{
	if (this != NULL)
	{
		this->left->InOrder();
		this->right->InOrder();
		cout << "Key : " << this->key << "\t|\tFreq : " << this->count << endl;
	}
}

void BTree::LevelOrder()
{
	if (this == NULL)
	{
		return;
	}

	queue<BTree*> que;
	que.push(this);
	que.push(nullptr);

	while (!que.empty()) 
	{
		BTree* current = que.front();

		que.pop();

		if (current != NULL)
		{
			cout << current->key << " ";
			if (current->left != NULL)
			{
				que.push(current->left.get());
			}

			if (current->right != NULL )
			{
				que.push(current->right.get());
			}
		}
		else 
		{
			if (!que.empty()) 
			{
				cout << endl;
				que.push(nullptr);
			}
		}
	}  

}

bool BTree::Insert(int key)
{
	if (this->key == -1)
	{
		this->key = key;
		this->count++;
		return true;
	}

	if (this->key == key)
	{
		(this->count)++;
		return true;
	}

	if (key < this->key)
	{
		if (this->left == NULL)
		{
			this->left.reset(new BTree());
		}

		return this->left->Insert(key);
	}
	else
	{
		if (this->right == NULL)
		{
			this->right.reset(new BTree());
		}

		return this->right->Insert(key);
	}
}

int BTree::GetFrequency(int key)
{
	if (this == NULL)
	{
		return 0;
	}

	if (this->key == key)
	{
		return this->count;
	}

	if (key < this->key)
	{
		return this->left->GetFrequency(key);
	}
	else
	{
		return this->right->GetFrequency(key);
	}
}

int BTree::GetMinValue()
{
	BTree* current = this;

	while (current && current->left != NULL)
		current = current->left.get();

	return current->key;
}

int BTree::GetMaxValue()
{
	BTree* current = this;

	while (current && current->right != NULL)
		current = current->right.get();

	return current->key;
}

bool BTree::Contains(int key)
{
	// Base Case  
	if (this == NULL)
		return false;

	queue<BTree*> que;

	que.push(this);

	while ( !que.empty() )
	{
		BTree* current = que.front();
		if (current->key == key)
			return true;

		que.pop();

		if (current->left != NULL)
		{
			que.push(current->left.get());
		}

		if (current->right != NULL)
		{
			que.push(current->right.get());
		}

	}

	return false;

}

void BTree::Remove(int key)
{
	DeleteNode(key);
}

void BTree::RemoveLeafs()
{
	DeleteLeaf();
}

std::shared_ptr<BTree> BTree::DeleteLeaf()
{
	if (this == NULL)
		return NULL;

	if (this->left == NULL && this->right == NULL) 
	{
		SharedThis().reset();
		return NULL;
	}

	// Else recursively delete in left and right 
	// subtrees. 
	this->left = this->left->DeleteLeaf();
	this->right = this->right->DeleteLeaf();

	return SharedThis();
}

shared_ptr<BTree> BTree::DeleteNode(int key)
{
	if ( this == NULL)
		return NULL;

	if (key < this->key)
	{
		this->left = this->left->DeleteNode(key);
	}
	else if (key > this->key)
	{
		this->right = this->right->DeleteNode(key);
	}
	else
	{
		//only one child or no child 
		if (this->left == NULL)
		{
			shared_ptr<BTree> temp = this->right;
			SharedThis().reset();
			return temp;
		}
		else if (this->right == NULL)
		{
			shared_ptr<BTree> temp = this->left;
			SharedThis().reset();
			return temp;
		}

		// node with two children: Get the inorder successor (smallest in the right subtree) 
		shared_ptr<BTree> temp = this->right->MinNode();

		// Copy the inorder successor's  
		// content to this node 
		this->key = temp->key;

		// Delete the inorder successor 
		this->right = this->right->DeleteNode( temp->key);
	}
	 
	return SharedThis();
}

shared_ptr<BTree> BTree::MinNode()
{
	shared_ptr<BTree> current = shared_from_this();

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

shared_ptr<BTree> BTree::MaxNode()
{
	shared_ptr<BTree> current = shared_from_this();

	while (current->right != NULL)
	{
		current = current->right;
	}

	return current;
}

std::shared_ptr<BTree> BTree::SharedThis()
{
	return shared_from_this();
}
