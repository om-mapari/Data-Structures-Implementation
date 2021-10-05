#include <iostream>
#include "SpanningTree.h"
#include "sp.cpp"
using namespace std;

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int choice;
	bool cont;
	SpanningTree ST;
	do
	{
		cout << "Spanning Tree Algorithms: "
				"\n1. Prim's"
				"\n2. Krushkals"
				"\n3. Exit"
			 << endl;
		cin >> choice;
		if (choice == 1)
		{
			ST.Pcreate();
			ST.prim();
			cout << "\nDo You want to continue to Krushkal for Same Graph true / false : ";
			cin >> cont;
			if (cont == true)
				ST.krushkal();
		}
		if (choice == 2)
		{
			ST.Kcreate();
			ST.krushkal();
		}
		else if (choice == 3)
			;
		//else cout << "\t>> Invalid Choice!" << endl;
	} while (choice != 3);
	return 0;
}