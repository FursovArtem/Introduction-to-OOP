#pragma once
#include <iostream>
using std::cout;
using std::endl;

class String;
String operator+(const String& lvalue, const String& rvalue);

class String
{
private:
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// Constructors:

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other)noexcept;
	String(String&& other)noexcept;
	~String();

	// Operators:

	String& operator=(const String& other)noexcept;
	String& operator=(String&& other)noexcept;
	String& operator+=(const String& rvalue);

	char operator[](int i)const;
	char& operator[](int i);

	// Methods:

	void print()const;
};