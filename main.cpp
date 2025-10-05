#include "Elephant.h"
#include "Fridge.h"

using namespace std;


int main()
{
	Fridge F;
	std::string a;
	cout << "Please enter a string as the elephant's name:" << endl;
	cin >> a;
	Elephant e(a);
	F.Open();
	F.PutIn(e);
	F.Close();
	return 0;
}