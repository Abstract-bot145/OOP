#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <string>
using namespace std;
class Elephant {
private:
	std::string name;
	double weight;
	double volume;

public:
	Elephant(string na)
	{
		name = na;
	}
	std::string getName() const {
		return name;
	}
	double getWeight() const {
		return weight;
	}
	double getVolume() const {
		return volume;
	}
};
#endif