#include "Point2D.h"
#include "Point3D.h"
#include <iostream>

int main() {
	std::cout << "===== Point2D ²âÊÔ =====" << std::endl;
	Point2D p1(1.0, 2.0);
	Point2D p2(4.0, 6.0);
	p1.show();
	p2.show();
	std::cout << "Á½µã¾àÀë: " << distance(p1, p2) << std::endl;
	p1.move(2, 3).show();

	std::cout << "\n===== Point3D ²âÊÔ =====" << std::endl;
	Point3D p3(1.0, 2.0, 3.0);
	Point3D p4(4.0, 6.0, 9.0);
	p3.show();
	p4.show();
	std::cout << "Á½µã¾àÀë: " << distance(p3, p4) << std::endl;
	p3.move(1, 1, 1).show();

	std::cout << "\n===== ³ÌÐò½áÊø =====" << std::endl;
	return 0;
}