#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"

class Point3D : public Point2D {
private:
	double z;
public:
	// 构造函数
	Point3D(double xVal = 0.0, double yVal = 0.0, double zVal = 0.0);

	// 析构函数
	~Point3D();

	// 移动点坐标（重写）
	Point3D& move(double deltaX, double deltaY, double deltaZ);

	// 显示点坐标（重写）
	void show() const;

	// 友元函数：计算两个三维点间的欧式距离
	friend double distance(const Point3D& p1, const Point3D& p2);
};

#endif // POINT3D_H