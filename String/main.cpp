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
	return *this = this->str + rvalue;
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

void main()
{
	setlocale(LC_ALL, "");
	String str1;	//Default constructor
	str1.print();

	String str2(5);	//1-arg constructor
	str2.print();

	String str3("Hello"); //1-arg constructor
	str3.print();

	String str4();	//не создает объект, объ€вл€етс€ функци€ str4(), 
	//котора€ ничего не принимает и возвращает объект класса String
//str4().print();

	String str5{};	//€вно вызываетс€ default constructor
	str5.print();

	String str6("World");
	str6.print();

	String str7{ "Compile" };
	str7.print();

	String str8 = str3; //Copy constructor
	str8.print();

	String str9;
	str9 = str6;
	str9.print();
}