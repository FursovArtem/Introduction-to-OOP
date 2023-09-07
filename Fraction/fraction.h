#pragma once
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
	int get_numerator()const;
	int get_denominator()const;
	int get_integer()const;
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	void set_integer(int integer);

	// Constructors:
	fraction();
	fraction(int integer);
	fraction(double decimal);
	fraction(int numerator, int denominator);
	fraction(int integer, int numerator, int denominator);
	fraction(const fraction& other);
	// ~Destructor:

	~fraction();

	// Assignment operator:

	fraction operator=(const fraction& rvalue);
	fraction operator+=(const fraction& rvalue);
	fraction operator-=(const fraction& rvalue);
	fraction operator*=(const fraction& rvalue);
	fraction operator/=(const fraction& rvalue);

	// Increment/Decrement:

	fraction& operator++();
	fraction& operator++(int);
	fraction& operator--();
	fraction& operator--(int);
	fraction& operator-();
	fraction& operator()(int integer, int numerator, int denominator);

	// Type-cast:
	operator int();
	operator double();

	// Methods:

	void print()const;
	int gcd(int num_1, int num_2);
	/*
	int lcd(int num_1, int num_2);
	*/
	fraction& correct();
	fraction& reduct();
};