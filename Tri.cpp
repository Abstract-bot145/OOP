#include<iostream>
#include<cmath>
using namespace std;

bool static ifTrangle(double a, double b, double c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return false;
	if (a + b > c && b + c > a && a + c > b)
		return true;
	else
		return false;
}
double  whatTriangle(double a, double b, double c)
{
	if (a * a + b * b < c * c || b * b + c * c < a * a || a * a + b * b < c * c)
		return -1;
	if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + b * b == c * c)
		return 0;
	if (a * a + b * b > c * c || b * b + c * c > a * a || a * a + b * b > c * c)
		return 1;
}

int main(){
class Triangle {
private:
	double a;
	double b;
	double c;
public:
	void setA(double a) { this->a = a; }
	void setB(double b) { this->b = b; }
	void setC(double c) { this->c = c; }
	double getA() { return a; }
	double getB() { return b; }
	double getC() { return c; }
	Triangle() {}
	Triangle(double a, double b, double c)
	{
		if (ifTrangle(a, b, c))
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}
		else
			cout << "This is not a triangle" << endl;
	}

	void setLength(double a, double b, double c)
	{
		if (ifTrangle(a, b, c))
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}
		else
			cout << "This is not a triangle" << endl;
	}
	void getPerimeter()
	{
		double s = a + b + c;
		cout << "Perimeter is " << s << endl;
	}
	void getArea()
	{
		double s = a + b + c;
		double S = sqrt(s * (s - a) * (s - b) * (s - c));
		cout << "Area is " << S << endl;
	}
	void whatTri()
	{
		if (whatTriangle(a, b, c)==-1)
		{
			cout << "This is a acute triangle" << endl;
		}
		if (whatTriangle(a, b, c) == 0)
		{
			cout << "This is a right triangle" << endl;
		}
		if (whatTriangle(a, b, c) == 1)
		{
			cout << "This is a obtuse triangle" << endl;
		}
	}





};
Triangle A;
A.setLength(3,4,5);
A.getPerimeter();
A.getArea();
A.whatTri();

}