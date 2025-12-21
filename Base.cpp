#include "Base.h"

// 静态成员初始化（必须放在cpp文件中，避免重复定义）
int Base::count = 0;

// 构造函数
Base::Base(int aVal, int bVal, int cVal) : a(aVal), b(bVal), c(cVal) {
	count++;
	std::cout << "Base 构造函数被调用，当前对象数: " << count << std::endl;
}

// 拷贝构造函数
Base::Base(const Base& other) : a(other.a), b(other.b), c(other.c) {
	count++;
	std::cout << "Base 拷贝构造函数被调用，当前对象数: " << count << std::endl;
}

// 析构函数
Base::~Base() {
	count--;
	std::cout << "Base 析构函数被调用，剩余对象数: " << count << std::endl;
}

// 显示所有数据成员
void Base::print() const {
	std::cout << "Base 对象数据成员: a=" << a << ", b=" << b << ", c=" << c << std::endl;
}

// 静态成员函数：返回当前对象数量
int Base::manage() {
	return count;
}