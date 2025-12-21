#include "DerivedClasses.h"
#include <iostream>

// ========== Derived1: 公有继承 ==========
Derived1::Derived1(int aVal, int bVal, int cVal, int dVal)
	: Base(aVal, bVal, cVal), d1(dVal) {
	std::cout << "Derived1 构造函数被调用" << std::endl;
}

Derived1::~Derived1() {
	std::cout << "Derived1 析构函数被调用" << std::endl;
}

void Derived1::printDerived1() const {
	std::cout << "Derived1 对象: ";
	print();  // 可以直接调用基类的公有成员函数
	std::cout << "派生类数据成员 d1=" << d1 << std::endl;
}

void Derived1::testAccess() {
	std::cout << "\n=== Derived1（公有继承）访问测试 ===" << std::endl;

	// 1. 可以直接访问公有成员 a
	a = 100;
	std::cout << "1. 直接访问基类公有成员 a: " << a << std::endl;

	// 2. 可以直接访问保护成员 b（在派生类内部）
	b = 200;
	std::cout << "2. 直接访问基类保护成员 b: " << b << std::endl;

	// 3. 不能直接访问私有成员 c，需要通过公有接口
	setC(300);
	std::cout << "3. 通过公有接口访问基类私有成员 c: " << getC() << std::endl;

	// 4. 可以访问基类的静态成员函数
	std::cout << "4. 当前对象总数: " << manage() << std::endl;
}

// ========== Derived2: 私有继承 ==========
Derived2::Derived2(int aVal, int bVal, int cVal, int dVal)
	: Base(aVal, bVal, cVal), d2(dVal) {
	std::cout << "Derived2 构造函数被调用" << std::endl;
}

Derived2::~Derived2() {
	std::cout << "Derived2 析构函数被调用" << std::endl;
}

void Derived2::printDerived2() const {
	std::cout << "Derived2 对象: ";
	// 在类内部可以调用基类的公有成员函数
	print();
	std::cout << "派生类数据成员 d2=" << d2 << std::endl;
}

void Derived2::testAccess() {
	std::cout << "\n=== Derived2（私有继承）访问测试 ===" << std::endl;

	// 1. a 现在是私有成员（在派生类内部可访问）
	a = 100;  // 在派生类内部可以访问
	std::cout << "1. 在派生类内部访问基类公有成员 a: " << a << std::endl;

	// 2. b 现在是私有成员（在派生类内部可访问）
	b = 200;
	std::cout << "2. 在派生类内部访问基类保护成员 b: " << b << std::endl;

	// 3. 不能直接访问 c，需要通过接口
	setC(300);
	std::cout << "3. 通过接口访问基类私有成员 c: " << getC() << std::endl;
}

// ========== Derived3: 保护继承 ==========
Derived3::Derived3(int aVal, int bVal, int cVal, int dVal)
	: Base(aVal, bVal, cVal), d3(dVal) {
	std::cout << "Derived3 构造函数被调用" << std::endl;
}

Derived3::~Derived3() {
	std::cout << "Derived3 析构函数被调用" << std::endl;
}

void Derived3::printDerived3() const {
	std::cout << "Derived3 对象: ";
	print();  // 在类内部可以调用基类的公有成员函数
	std::cout << "派生类数据成员 d3=" << d3 << std::endl;
}

void Derived3::testAccess() {
	std::cout << "\n=== Derived3（保护继承）访问测试 ===" << std::endl;

	// 1. a 现在是保护成员（在派生类内部可访问）
	a = 100;
	std::cout << "1. 在派生类内部访问基类公有成员 a: " << a << std::endl;

	// 2. b 现在是保护成员（在派生类内部可访问）
	b = 200;
	std::cout << "2. 在派生类内部访问基类保护成员 b: " << b << std::endl;

	// 3. 不能直接访问 c，需要通过接口
	setC(300);
	std::cout << "3. 通过接口访问基类私有成员 c: " << getC() << std::endl;
}