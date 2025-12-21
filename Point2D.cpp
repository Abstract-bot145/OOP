#include "Point2D.h"

// 构造函数
Point2D::Point2D(double xVal, double yVal) : x(xVal), y(yVal) {
	std::cout << "Point2D 构造函数被调用 (" << x << ", " << y << ")" << std::endl;
}

// 析构函数
Point2D::~Point2D() {
	std::cout << "Point2D 析构函数被调用 (" << x << ", " << y << ")" << std::endl;
}

// 移动点坐标
Point2D& Point2D::move(double deltaX, double deltaY) {
	x += deltaX;
	y += deltaY;
	return *this;
}

// 显示点坐标
void Point2D::show() const {
	std::cout << "Point2D: (" << x << ", " << y << ")" << std::endl;
}

// 友元函数：计算两点间的欧式距离
double distance(const Point2D& p1, const Point2D& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}