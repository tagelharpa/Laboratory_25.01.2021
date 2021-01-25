#include<iostream>

using namespace std;

int main()
{
	setlocale (LC_ALL,"ru")
	int n, m;
	cout << "Введите переменную n" << endl;
	cin >> n;
	cout << "Введите переменную m" << endl;
	cin >> m;
	a = n++ + m;
	cout << " n++ +m  Решение : " << a << endl;
	b = m-- > n;
	cout << " m-- > n  Решение : " << b << endl;
	c = n-- > m;
	cout << " n-- > m  Решение : " << c << endl;
}
	
