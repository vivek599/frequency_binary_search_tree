#include "BinarySearchTree.h"


BTree::BTree()
{
	this->key = -1;
	this->count = 0;
}

BTree::~BTree()
{

}

void BTree::inorder()
{
	if (this != NULL)
	{
		this->left->inorder();
		cout << "Key : " << this->key << "\t|\tFreq : " << this->count << endl;
		this->right->inorder();
	}
}

bool BTree::insert(int key)
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

		return this->left->insert(key);
	}
	else
	{
		if (this->right == NULL)
		{
			this->right.reset(new BTree());
		}

		return this->right->insert(key);
	}
}

int BTree::freq(int key)
{
	if (this == NULL)
	{
		return -1;
	}

	if (this->key == key)
	{
		return this->count;
	}

	if (key < this->key)
	{
		return this->left->freq(key);
	}
	else
	{
		return this->right->freq(key);
	}
}

int BTree::minValue()
{
	BTree* current = this;

	while (current && current->left != NULL)
		current = current->left.get();

	return current->key;
}

int BTree::maxValue()
{
	BTree* current = this;

	while (current && current->right != NULL)
		current = current->right.get();

	return current->key;
}

bool BTree::contains(int key)
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
	deleteNode(key);
}

shared_ptr<BTree> BTree::deleteNode(int key)
{
	if ( this == NULL)
		return NULL;

	if (key < this->key)
	{
		this->left = this->left->deleteNode(key);
	}
	else if (key > this->key)
	{
		this->right = this->right->deleteNode(key);
	}
	else
	{
		//only one child or no child 
		if (this->left == NULL)
		{
			shared_ptr<BTree> temp = this->right;
			GetSharedThis().reset();
			return temp;
		}
		else if (this->right == NULL)
		{
			shared_ptr<BTree> temp = this->left;
			GetSharedThis().reset();
			return temp;
		}

		// node with two children: Get the inorder successor (smallest in the right subtree) 
		shared_ptr<BTree> temp = this->right->minNode();

		// Copy the inorder successor's  
		// content to this node 
		this->key = temp->key;

		// Delete the inorder successor 
		this->right = this->right->deleteNode( temp->key);
	}
	 
	return GetSharedThis();
}

shared_ptr<BTree> BTree::minNode()
{
	shared_ptr<BTree> current = shared_from_this();

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}

shared_ptr<BTree> BTree::maxNode()
{
	shared_ptr<BTree> current = shared_from_this();

	while (current->right != NULL)
	{
		current = current->right;
	}

	return current;
}
