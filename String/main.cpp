#include "String.h"

void main()
{
	setlocale(LC_ALL, "");
	String str1;	//Default constructor
	str1.print();

	String str2(5);	//1-arg constructor
	str2.print();

	String str3("Hello"); //1-arg constructor
	str3.print();

	String str4();	//�� ������� ������, ����������� ������� str4(), 
	//������� ������ �� ��������� � ���������� ������ ������ String
//str4().print();

	String str5{};	//���� ���������� default constructor
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