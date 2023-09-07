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
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	// Constructors:

	explicit String(int size = 80)
	{
		// default
		this->size = size;
		this->str = new char[size] {};
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
	}
	String(const String& other)noexcept
	{
		//Deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	}
	String(String&& other)noexcept
	{
		//Shallow copy
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
	}
	~String()
	{
		delete[] str;
	}

	// Operators:

	String& operator=(const String& other)noexcept
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		return *this;
	}
	String& operator=(String&& other)noexcept
	{
		if (this == &other) return *this;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
	}
	String& operator+=(const String& rvalue)
	{
		return *this = this->str + rvalue;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	// Methods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

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

void main()
{
	setlocale(LC_ALL, "");
	String str1 = "Hello";
	String str2 = "World";
	str1 += str2;
	cout << str1 << endl;
}