#include "fraction.h"

#define delimiter "\n--------------------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "");
	fraction A(0, 21, 6);
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
	A -= E;
	A.print();
	cout << delimiter;

	A = -A;
	A.print();
	A(5, 67, 23);
	cout << (double)A << endl;
	cout << (fraction)A << endl;

	fraction S;
	cin >> S;
	cout << S << endl;

	fraction X = 2.76;
	cout << X << endl;
}