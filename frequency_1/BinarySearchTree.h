#pragma once

#include <iostream>

#include <fstream>
#include <algorithm>
#include <queue>
#include <memory>

using namespace std;




class BTree : public enable_shared_from_this<BTree>
{
private:

	int key;
	int count;
	shared_ptr<BTree> left;
	shared_ptr<BTree> right;

	shared_ptr<BTree> deleteNode(int key);
	shared_ptr<BTree> minNode();
	shared_ptr<BTree> maxNode();
	
	shared_ptr<BTree> GetSharedThis()
	{
		return shared_from_this();
	}

public:
	BTree();
	~BTree();


	void inorder();

	bool insert(int key);

	int freq(int key);

	int minValue();

	int maxValue();

	bool contains(int key);
	void Remove(int key);


};

