#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Point
{
private:
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	Point()
	{
		x = y = double();
	}
	Point(double x)
	{
		this->x = x;
		this->y = double();
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	~Point()
	{

	}
	// Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	void print_distance()const
	{
		cout << "Расстояние по координате x: " << x << "\tРасстояние по координате y: " << y << endl;
	}
	Point distance(Point X)
	{
		Point result;
		result.x = abs(X.x - this->x);
		result.y = abs(X.y - this->y);
		return result;
	}
};

Point distance(Point A, Point B)
{
	Point result;
	result.set_x(abs(A.get_x() - B.get_x()));
	result.set_y(abs(A.get_y() - B.get_y()));
	return result;
}

void main()
{
	setlocale(LC_ALL, "");
	Point A(2, 3);
	Point B(20, 30);

	Point A_B_distance_method = A.distance(B);
	A_B_distance_method.print_distance();

	Point A_B_distance_function = distance(A, B);
	A_B_distance_function.print_distance();
}