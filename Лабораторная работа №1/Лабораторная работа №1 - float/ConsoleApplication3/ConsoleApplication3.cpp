#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	float  a, b, c, d, e;
	cout << " Введите а: " << endl;
	cin >> a;
	cout << " Введите b: " << endl;
	cin >> b;
	c = pow(a + b, 2); d = pow(a, 2) + 2 * a*b; e = pow(b, 2);
	cout << " Ваш результат : " << (float)(c - d) / e << endl;
}
