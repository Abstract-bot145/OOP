#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Point2D {
private:
	double x, y;
public:
	// 构造函数
	Point2D(double xVal = 0.0, double yVal = 0.0);

	// 析构函数
	~Point2D();

	// 移动点坐标
	Point2D& move(double deltaX, double deltaY);

	// 显示点坐标（const 成员函数）
	void show() const;

	// 友元函数：计算两点间的欧式距离
	friend double distance(const Point2D& p1, const Point2D& p2);
};

#endif // POINT2D_H