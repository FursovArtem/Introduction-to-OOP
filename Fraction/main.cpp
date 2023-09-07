#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class fraction
{
private:
	int numerator;
	int denominator;
	int integer;
public:
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_integer()const
	{
		return integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}

	// Constructors:
	fraction()
	{
		// default constructor
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
	}
	fraction(int integer)
	{
		// 1-arg constructor
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	fraction(double decimal)
	{
		// from double constructor
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		correct().reduct();
	}
	fraction(int numerator, int denominator)
	{
		// 2-arg constructor
		this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	fraction(int integer, int numerator, int denominator)
	{
		// 3-arg constructor
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
	}
	fraction(const fraction& other)
	{
		// copy
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	// ~Destructor:

	~fraction()
	{

	}

	// Assignment operator:

	fraction operator=(const fraction& rvalue)
	{
		this->integer = rvalue.integer;
		this->numerator = rvalue.numerator;
		this->denominator = rvalue.denominator;
		return *this;
	}
	fraction operator+=(const fraction& rvalue)
	{
		fraction temp;
		temp.integer = 0;
		temp.numerator = (
			(this->integer * this->denominator + this->numerator) * rvalue.denominator +
			(rvalue.integer * rvalue.denominator + rvalue.numerator) * this->denominator
			);
		temp.denominator = this->denominator * rvalue.denominator;
		temp.correct().reduct();
		return *this = temp;
	}
	fraction operator-=(const fraction& rvalue)
	{
		fraction temp;
		temp.integer = 0;
		temp.numerator = (
			(this->integer * this->denominator + this->numerator) * rvalue.denominator -
			(rvalue.integer * rvalue.denominator + rvalue.numerator) * this->denominator
			);
		temp.denominator = this->denominator * rvalue.denominator;
		temp.correct().reduct();
		return *this = temp;
	}
	fraction operator*=(const fraction& rvalue)
	{
		fraction temp;
		temp.integer = 0;
		temp.numerator = (
			(this->integer * this->denominator + this->numerator) *
			(rvalue.integer * rvalue.denominator + rvalue.numerator)
			);
		temp.denominator = this->denominator * rvalue.denominator;
		temp.correct().reduct();
		return *this = temp;
	}
	fraction operator/=(const fraction& rvalue)
	{
		fraction temp;
		temp.integer = 0;
		temp.numerator = (this->integer * this->denominator + this->numerator) * rvalue.denominator;
		temp.denominator = (rvalue.integer * rvalue.denominator + rvalue.numerator) * this->denominator;
		temp.correct();
		temp.reduct();
		return *this = temp;
	}

	// Increment/Decrement:

	fraction& operator++()		// prefix ++
	{
		integer++;
		return *this;
	}
	fraction& operator++(int)	// postfix ++
	{
		fraction old = *this;
		integer++;
		return old;
	}
	fraction& operator--()		// prefix --
	{
		integer--;
		return *this;
	}
	fraction& operator--(int)	// postfix --
	{
		fraction old = *this;
		integer--;
		return old;
	}
	fraction& operator-()		// unary -
	{
		integer = -integer;
		return *this;
	}
	fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	// Type-cast:
	operator int()
	{
		return correct().integer;
	}
	operator double()
	{
		return integer + numerator / (double)denominator;
	}

	// Methods:

	void print()const
	{
		cout << "Целая часть = " << integer << "\tДробная часть = " << numerator << " / " << denominator << endl;
	}
	int gcd(int num_1, int num_2)
	{
		// greatest common divisor method
		// метод НОД
		while (num_1 > 0 && num_2 > 0)
		{
			if (num_1 > num_2)
			{
				num_1 %= num_2;
			}
			else
			{
				num_2 %= num_1;
			}
		}
		return num_1 + num_2;
	}
	/*
	int lcd(int num_1, int num_2)
	{
		// least common divisor method
		// метод НОК
		return num_1 * num_2 / gcd(num_1, num_2);
	}
	*/
	fraction& correct()		// корректировка целой части (если числитель больше знаменателя)
	{
		if (numerator >= 0)
		{
			while (numerator >= denominator)
			{
				numerator -= denominator;
				integer++;
			}
			return *this;
		}
		else
		{
			numerator = -numerator;
			while (numerator >= denominator)
			{
				numerator -= denominator;
				integer--;
			}
			return *this;
		}
	}
	fraction& reduct()		// сокращение дроби по НОД
	{
		int gcdiv = gcd(numerator, denominator);
		numerator /= gcdiv;
		denominator /= gcdiv;
		return *this;
	}
};

#define delimiter "\n--------------------------------------------------------------\n"

fraction operator+(const fraction& lvalue, const fraction& rvalue)
{
	fraction result;
	result.set_integer(0);
	result.set_numerator(
		(lvalue.get_integer() * lvalue.get_denominator() + lvalue.get_numerator()) * rvalue.get_denominator() +
		(rvalue.get_integer() * rvalue.get_denominator() + rvalue.get_numerator()) * lvalue.get_denominator()
	);
	result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
	return result.correct().reduct();
}
fraction operator-(const fraction& lvalue, const fraction& rvalue)
{
	fraction result;
	result.set_integer(0);
	result.set_numerator(
		(lvalue.get_integer() * lvalue.get_denominator() + lvalue.get_numerator()) * rvalue.get_denominator() -
		(rvalue.get_integer() * rvalue.get_denominator() + rvalue.get_numerator()) * lvalue.get_denominator()
	);
	result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
	return result.correct().reduct();
}
fraction operator*(const fraction& lvalue, const fraction& rvalue)
{
	fraction result;
	result.set_integer(0);
	result.set_numerator(
		(lvalue.get_integer() * lvalue.get_denominator() + lvalue.get_numerator()) *
		(rvalue.get_integer() * rvalue.get_denominator() + rvalue.get_numerator())
	);
	result.set_denominator(lvalue.get_denominator() * rvalue.get_denominator());
	return result.correct().reduct();
}
fraction operator/(const fraction& lvalue, const fraction& rvalue)
{
	fraction result;
	result.set_integer(0);
	result.set_numerator(
		(lvalue.get_integer() * lvalue.get_denominator() + lvalue.get_numerator()) * rvalue.get_denominator());
	result.set_denominator(
		(rvalue.get_integer() * rvalue.get_denominator() + rvalue.get_numerator()) * lvalue.get_denominator());
	return result.correct().reduct();
}
bool operator==(const fraction& lvalue, const fraction& rvalue)
{
	fraction left = lvalue;
	fraction right = rvalue;
	left.correct().reduct();
	right.correct().reduct();
	return left.get_integer() == right.get_integer() && left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator();
}
bool operator!=(const fraction& lvalue, const fraction& rvalue)
{
	return !(lvalue == rvalue);
}
bool operator>(const fraction& lvalue, const fraction& rvalue)
{
	if (lvalue.get_integer() > rvalue.get_integer()) return true;
	else if (lvalue.get_integer() < rvalue.get_integer()) return false;
	else return lvalue.get_numerator() * rvalue.get_denominator() > rvalue.get_numerator() * lvalue.get_denominator() ? true : false;
}
bool operator<(const fraction& lvalue, const fraction& rvalue)
{
	if (lvalue.get_integer() < rvalue.get_integer()) return true;
	else if (lvalue.get_integer() > rvalue.get_integer()) return false;
	else return lvalue.get_numerator() * rvalue.get_denominator() < rvalue.get_numerator() * lvalue.get_denominator() ? true : false;
}
bool operator>=(const fraction& lvalue, const fraction& rvalue)
{
	return !(lvalue < rvalue);
}
bool operator<=(const fraction& lvalue, const fraction& rvalue)
{
	return !(lvalue > rvalue);
}
std::ostream& operator<<(std::ostream& os, const fraction& obj)
{
	return os << "Целая часть = " << obj.get_integer() << "\tДробная часть = " << obj.get_numerator() << " / " << obj.get_denominator();
}
std::istream& operator>>(std::istream& is, fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	const int size = 256;
	char sz_buffer[size]{};
	is >> sz_buffer;
	int number[3] = {};
	int n = 0;
	char delimiters[] = "()/";
	
	for (char* pch = strtok(sz_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = std::atoi(pch); //atoi - ascii-string to integer
	}

	switch (n)
	{
	case 1: obj = fraction(number[0]); break;
	case 2: obj = fraction(number[0], number[1]); break;
	case 3: obj = fraction(number[0], number[1], number[2]);
	}
	return is;
}

void main()
{
	setlocale(LC_ALL, "");
	/*fraction A(0, 21, 6);
	fraction B(5, 13, 7);
	A.print();
	B.print();
	cout << delimiter;

	A.correct();
	B.correct();
	A.print();
	B.print();
	cout << delimiter;

	A.reduct();
	B.reduct();
	A.print();
	B.print();
	cout << delimiter;

	fraction C = A + B;
	C.print();
	cout << delimiter;

	fraction D = A - B;
	D.print();
	cout << delimiter;

	fraction E = A * B;
	E.print();
	fraction F = A / B;
	F.print();
	cout << delimiter;

	cout << (B >= A) << endl;
	fraction G;
	--G;
	G--;
	G.print();
	cout << A + B << endl;
	cout << delimiter;

	cout << A(1, 2, 3) << endl;
	cout << A(0, 21, 6) << endl;
	A -= B;
	A.print();
	cout << delimiter;

	A = -A;
	A.print();
	A(5, 67, 23);
	cout << (double)A << endl;
	cout << (fraction)A << endl;

	fraction S;
	cin >> S;
	cout << S << endl;*/

	fraction A = 2.76;
	cout << A << endl;
}