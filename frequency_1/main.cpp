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

	shared_ptr<BTree> root(new BTree());

#if 0

	root->Insert(100);
	root->Insert(900);
	root->Insert(20);
	root->Insert(980);
	root->Insert(90);
	root->Insert(70);
	root->Insert(200);
	
	cout << "Tree height : " << root->GetHeight() << endl;
	cout << "Tree Size : " << root->GetSize() << endl;

	cout << endl;
	root->LevelOrder();
	cout << endl;

	cout << "RemoveLeafs ..." << endl;
	root->RemoveLeafs();
	cout << endl;
	root->LevelOrder();
	cout << endl;

#else

	cout << "Reading file..." << endl;
	while (!infile.eof())
	{
		int tmpInt = 0;

		infile >> tmpInt;

		root->Insert(tmpInt);
	}

	cout << "Reading file finished..." << endl;

	infile.close();

	cout << "Tree height : " << root->GetHeight() << endl;
	cout << "Tree Size : " << root->GetSize() << endl;

	cout << "min : " << root->GetMinValue() << endl;
	cout << "max : " << root->GetMaxValue() << endl;

	cout << "816 is present : " << (root->Contains(816) ? "Yes" : "No") << endl;
	cout << "1001 is present : " << (root->Contains(1001) ? "Yes" : "No") << endl;

	root->Remove(816);
	cout << "816 is present : " << (root->Contains(816) ? "Yes" : "No") << endl;
	
	cout << "424 is present : " << (root->Contains(424) ? "Yes" : "No") << endl;
	root->Remove(424);
	cout << "424 is present : " << (root->Contains(424) ? "Yes" : "No") << endl;

	while ( true )
	{
		cout << "Enter a number between 0 to 1000 : ";
		cin >> num;

		if (num == -1)
		{
			break;;
		}

		cout << num << " is " << (root->Contains(num) ? "present." : "Not present.") << endl;

		num = num < 0 ? 0 : num > 1000 ? 1000 : num;

		cout << "freq of " << num << " is " << root->GetFrequency(num) << endl;
		
		system("pause");
		system("cls");
	}

#endif

	root->LevelOrder();
	cout << endl;
	//root->InOrder();

	system("pause");

	return 0;
}
