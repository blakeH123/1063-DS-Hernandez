```cpp
#include <fstream>
#include <iostream>
#include <string>

#include "DBList.h"

using namespace std;

int main()
{	DBList List;
	string a;
	string tempdata;
	int seed, xmult, multiplier;
	int deletecount = 0;

	ifstream fin("animals.txt");
	ofstream ofile;
	ofile.open("eliminate.txt");

	cout << "Please enter a random seed number." << '\n' << '\n';
	cin >> seed;
	cout << "Please enter an integer multiplier between 1 and 13 inclusive."
		 << '\n'
		 << '\n';
	cin >> xmult;

	srand(seed); // seeds random number generator with user prompted seed

	ofile << "/////////////////////////////////////////////////////////////////"
			 "////////////////////////////"
		  << '\n'
		  << "// ProgramName: Program 3 Survivor" << '\n'
		  << "// Author: Blake Hernandez" << '\n'
		  << "// Description: " << '\n'
      << "// This Program reads in strings from a file and inseerts them into a circular doubley linked list. After the list is completed, a multiplier, the product of a string length and a user prompted multiplier. the multiplier is then determins how the list is traversed and which items get deleted. Itesm are deleted until one node is left in the list."
		  << "// Course: 1063 Data Structures" << '\n'
		  << "// Semester: Spring 2018" << '\n'
		  << "// Date: 27 04 2018" << '\n'
		  << "/////////////////////////////////////////////////////////////////"
			 "////////////////////////////"
		  << '\n'
		  << '\n';

	while (fin >> a)
	{	List.InsertRear(a); // rear insert to keep in alphabetical order
	}
	List.InsertRear(a);

	fin.clear();
	fin.seekg(0, std::ios::beg); // back to the start!

	while (!List.Empty())
	{	while (fin >> a) 
	  {	multiplier = a.length() * xmult;

			if (multiplier % 2 == 0)
			{	tempdata = List.TraverseNext(multiplier); // variable to print delted item
			} else
			{	tempdata = List.TraversePrev(multiplier);
			}

			if (deletecount == 0)
			{	ofile << "First: " << tempdata << '\n';
			} else if (deletecount % 11 == 0)
			{	ofile << "- " << tempdata << '\n';
			}
			deletecount++;
			List.Print();
		}
	}
  ofile << "WINNER: " << tempdata << " !!";
  fin.close();
  ofile.close();
  return 0;
}
```
