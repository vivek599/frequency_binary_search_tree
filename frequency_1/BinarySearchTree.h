#pragma once

#include <iostream>

#include <fstream>
#include <algorithm>
#include <memory>

using namespace std;




class BTree
{
private:

	int key;
	int count;
	unique_ptr<BTree> left;
	unique_ptr<BTree> right;

public:
	BTree();
	~BTree();


	void inorder();

	bool insert(int key);

	int freq(int key);

	int minValue();

	int maxValue();




};

