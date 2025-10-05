#ifndef FRIDGE

#include <iostream>
#include "Elephant.h"
using namespace std;

class Fridge
{
public:
	void Open(void)
	{
		cout << "Fridge is opened." << endl;
	}

	void PutIn(Elephant& ele)
	{
		cout << "The elephant " << ele.getName() << " has been put into the fridge." << endl;
	}

	void Close(void)
	{
		cout << "Fridge is closed." << endl;
	}
};

#endif 