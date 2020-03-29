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

	shared_ptr<BTree> SharedThis();
	shared_ptr<BTree> DeleteLeaf();
	shared_ptr<BTree> DeleteNode(int key);
	shared_ptr<BTree> MinNode();
	shared_ptr<BTree> MaxNode();

public:
	BTree();
	~BTree();


	void PreOrder();
	void InOrder();
	void PostOrder();

	void LevelOrder();

	bool Insert(int key);

	int GetFrequency(int key);

	int GetMinValue();

	int GetMaxValue();

	bool Contains(int key);
	void Remove(int key);
	void RemoveLeafs();


};

