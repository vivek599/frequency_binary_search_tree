#include <iostream>


#include "BinarySearchTree.h"

using namespace std;


int main()
{


	int num = 0;

	ifstream infile("../data/SensorIntensityData.txt" );

	if (!infile.good())
	{
		cout << "Error opening file..." << endl;
		system("pause");
		return 0;
	}

	unique_ptr<BTree> root(new BTree());

	cout << "Reading file..." << endl;
	while (!infile.eof())
	{
		int tmpInt = 0;

		infile >> tmpInt;

		root->insert(tmpInt);
	}

	cout << "Reading file finished..." << endl;

	infile.close();

	cout << "min : " << root->minValue() << endl;
	cout << "max : " << root->maxValue() << endl;

	while ( true )
	{
		cout << "Enter a number between 0 to 1000 : ";
		cin >> num;
		
		if (num == -1)
		{
			break;;
		}

		num = num < 0 ? 0 : num > 1000 ? 1000 : num;

		cout << "freq of " << num << " is " << root->freq(num) << endl;
		
		system("pause");
		system("cls");
	}


	root->inorder();

	system("pause");

	return 0;
}
