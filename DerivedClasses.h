#ifndef DERIVEDCLASSES_H
#define DERIVEDCLASSES_H

#include "Base.h"

// 公有继承
class Derived1 : public Base {
private:
	int d1;
public:
	Derived1(int aVal = 0, int bVal = 0, int cVal = 0, int dVal = 0);
	~Derived1();
	void printDerived1() const;
	void testAccess();
};

// 私有继承
class Derived2 : private Base {
private:
	int d2;
public:
	Derived2(int aVal = 0, int bVal = 0, int cVal = 0, int dVal = 0);
	~Derived2();
	void printDerived2() const;
	// 由于私有继承，需要提供访问基类公有成员的接口
	int getA() const { return a; } // a 变为私有，需要重新暴露
	void setA(int val) { a = val; }
	void testAccess();
};

// 保护继承
class Derived3 : protected Base {
private:
	int d3;
public:
	Derived3(int aVal = 0, int bVal = 0, int cVal = 0, int dVal = 0);
	~Derived3();
	void printDerived3() const;
	void testAccess();
	// 由于保护继承，a 变为保护成员，在类外不可直接访问
	int getA() const { return a; }
	void setA(int val) { a = val; }
};

#endif // DERIVEDCLASSES_H