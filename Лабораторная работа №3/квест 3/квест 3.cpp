#include <iostream>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a = 0.1, b = 1, eps = 0.0001;  
	int n = 10, k = 10;
	int i;
	double step = (b - a) / k;

	double x = a;
	double s = 1;
	double ai = 1;
	while (x <= b)       
	{
		cout << "X=" << x;
		s = 1;           
		ai = 1;
		for (i = 1; i < n; i++)   
		{
			ai *= log(3) / i * x;   
			s += ai;
		}
		cout << " SN=" << s;

		s = 1;          
		ai = 1;
		i = 1;
		while (ai > eps)        
		{
			ai *= log(3) / i * x;
			s += ai;
			i++;
		}
		cout << " SE=" << s << " Y=" << pow(3, x) << endl;
		x += step;
	}
	return 0;
}

