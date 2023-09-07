#include "String.h"

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
// Constructors:

// ключевое слово explicit можно писать только внутри класса
String::String(int size) : size(size), str(new char[size] {})
{
	// default
	//this->size = size;
	//this->str = new char[size] {};
}
String::String(const char* str) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
}
String::String(const String& other)noexcept : String(other.str)
{
	//Deep copy
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
}
String::String(String&& other)noexcept : size(other.size), str(other.str)
{
	//Shallow copy
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
}
String::~String()
{
	delete[] str;
}

// Operators:

String& String::operator=(const String& other)noexcept
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	return *this;
}
String& String::operator=(String&& other)noexcept
{
	if (this == &other) return *this;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
}
String& String::operator+=(const String& rvalue)
{
	return *this = *this + rvalue;
}

char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

// Methods:

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& lvalue, const String& rvalue)
{
	String result(lvalue.get_size() + rvalue.get_size() - 1);
	for (int i = 0; i < lvalue.get_size(); i++)result[i] = lvalue[i];
	for (int i = 0; i < rvalue.get_size(); i++)result[lvalue.get_size() - 1 + i] = rvalue[i];
	return result;
}
std::ostream& operator <<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
