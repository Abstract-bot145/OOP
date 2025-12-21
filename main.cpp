#include "DerivedClasses.h"
#include <iostream>

int main() {
	std::cout << "========== 任务三：继承方式验证 ==========\n" << std::endl;

	// 测试构造函数和析构函数调用顺序
	std::cout << "=== 创建对象测试 ===" << std::endl;
	Derived1 obj1(1, 2, 3, 4);
	Derived2 obj2(10, 20, 30, 40);
	Derived3 obj3(100, 200, 300, 400);

	std::cout << "\n=== 显示对象信息 ===" << std::endl;
	obj1.printDerived1();
	obj2.printDerived2();
	obj3.printDerived3();

	std::cout << "\n=== 测试访问权限 ===" << std::endl;
	obj1.testAccess();
	obj2.testAccess();
	obj3.testAccess();

	std::cout << "\n=== 测试类外访问 ===" << std::endl;
	// Derived1 公有继承测试
	std::cout << "Derived1.a = " << obj1.a << std::endl;
	obj1.print();  // 可以调用基类公有函数

	// Derived2 私有继承测试（不能直接访问）
	// obj2.a;  // 错误：a 是私有的
	std::cout << "Derived2.getA() = " << obj2.getA() << std::endl;

	// Derived3 保护继承测试（不能直接访问）
	// obj3.a;  // 错误：a 是保护的
	std::cout << "Derived3.getA() = " << obj3.getA() << std::endl;

	std::cout << "\n=== 测试对象计数 ===" << std::endl;
	std::cout << "当前对象总数: " << Base::manage() << std::endl;

	std::cout << "\n========== 程序结束 ==========" << std::endl;
	return 0;
}