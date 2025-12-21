#include "Point3D.h"

// 构造函数
Point3D::Point3D(double xVal, double yVal, double zVal) : Point2D(xVal, yVal), z(zVal) {
	std::cout << "Point3D 构造函数被调用 (" << xVal << ", " << yVal << ", " << z << ")" << std::endl;
}

// 析构函数
Point3D::~Point3D() {
	std::cout << "Point3D 析构函数被调用 (" << "x, y, " << z << ")" << std::endl;
}

// 移动点坐标（重写）
Point3D& Point3D::move(double deltaX, double deltaY, double deltaZ) {
	Point2D::move(deltaX, deltaY);
	z += deltaZ;
	return *this;
}

// 显示点坐标（重写）
void Point3D::show() const {
	// 由于 x, y 是基类私有成员，无法直接访问，因此调用基类的 show 函数
	// 也可以考虑将 x, y 声明为 protected 以便派生类直接访问（本实验未要求）
	std::cout << "Point3D: (";
	// 这里为了完整输出，直接调用基类 show 并补上 z
	// 由于 show 是 const 成员函数，不能修改成员，此处采用间接方式
	Point2D::show();
	std::cout << ", " << z << ")" << std::endl;
}

// 友元函数：计算两个三维点间的欧式距离
double distance(const Point3D& p1, const Point3D& p2) {
	// 调用基类 distance 计算 xy 平面距离
	double xyDist = distance(static_cast<const Point2D&>(p1), static_cast<const Point2D&>(p2));
	return sqrt(pow(xyDist, 2) + pow(p1.z - p2.z, 2));
}