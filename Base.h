#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base {
private:
	int c;          // 私有数据成员
	static int count; // 静态私有成员，用于统计对象个数
public:
	int a;          // 公有数据成员
protected:
	int b;          // 保护数据成员

public:
	// 构造函数
	Base(int aVal = 0, int bVal = 0, int cVal = 0);

	// 拷贝构造函数
	Base(const Base& other);

	// 析构函数
	virtual ~Base();  // 声明为虚析构函数，便于继承

	// 显示所有数据成员
	void print() const;

	// 静态成员函数：管理对象计数
	static int manage();

	// 访问私有成员 c 的公有接口（用于派生类间接访问）
	int getC() const { return c; }
	void setC(int val) { c = val; }
};

// 注意：静态成员 count 的初始化放在 Base.cpp 中

#endif // BASE_H