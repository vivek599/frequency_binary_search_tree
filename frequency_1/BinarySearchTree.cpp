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
	// If key already exists in BST,  
	// increment count and return 

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

	/* Otherwise, recur down the tree */
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