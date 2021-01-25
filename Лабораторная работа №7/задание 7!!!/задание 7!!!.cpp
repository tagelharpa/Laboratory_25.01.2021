#include <iostream>
#include <math.h>

using namespace std;


void printFIO(const char* last_name = "Ivanov", const char* first_name = "Ivan", const char* patronymic = "Ivanovich")
{
	cout << last_name << " " << first_name << " " << patronymic << endl;
	return;
}


int getMin(int n, ...)
{
	int *p = &n;
	p++;      
	int num = *(p++); 
	int min = num;
	for (; n > 1; n--)    
	{
		num = *(p++); 
		if (min > num)
			min = num;
	}
	return min;

}


double getAVG(int mas[], int n)
{
	double s = 0;            
	for (int i = 0; i < n; i++)
		s += mas[i];                 
	return s / n;
}

double getAVG(double mas[], int n)
{
	double s = 0;             
	for (int i = 0; i < n; i++)
		s += mas[i];                 
	return s / n;
}


double getAVG(char mas[], int n)
{
	double s = 0;             
	for (int i = 0; i < n; i++)
		s += mas[i];                 
	return s / n;
}


template<class T>
double getMasAVG(T mas[], int n)
{
	double s = 0;             
	for (int i = 0; i < n; i++)
		s += mas[i];                 
	return s / n;
}


typedef double(*fptr)(double);


double root(fptr f, double a, double b, double lambda, double eps)
{
	double x = (a + b) / 2;           
	while (fabs((*f)(x)) > eps)    
	{
		x = x + lambda * (*f)(x);      
	}

	return x;
}

double testf(double x)
{
	return 3 * sin(sqrt(x)) + 0.35*x - 3.8;
}


int main()
{
	setlocale(LC_ALL, "");
	cout << "Использование функции с умалчиваемыми параметрами" << endl;
	
	printFIO("Sidorov", "Pavel", "Aleksandrovich");
	
	printFIO();
	
	printFIO("Petrov", "Sergey");

	cout << "\nИспользование функции с переменным числом параметров" << endl;
	
	cout << "Минимальный элемент в списке [2, 1, 5]: " << getMin(3, 2, 1, 5) << endl;
	
	cout << "Минимальный элемент в списке [4, 6, 2, 8, 9, 5, 3, -4, -6, 12]: " << getMin(10, 4, 6, 2, 8, 9, 5, 3, -4, -6, 12) << endl;

	cout << "\nИспользование перегруженных функции" << endl;
	int mas1[] = { 1, 2, 5, 3, 2 };
	double mas2[] = { 2.8, 3.6, 4.1, 13.2, 16.4, 9.3 };
	char mas3[] = { 'a', 'b', 'c', 'd' };
	cout << "Среднее арифметическое среди элементов массива [1, 2, 5, 3, 2]: " << getAVG(mas1, 5) << endl;
	cout << "Среднее арифметическое среди элементов массива [2.8, 3.6, 4.1, 13.2, 16.4, 9.3]: " << getAVG(mas2, 6) << endl;
	cout << "Среднее арифметическое среди элементов массива ['a', 'b', 'c', 'd']: " << getAVG(mas3, 4) << endl;


	cout << "\nИспользование шаблона функции" << endl;
	cout << "Среднее арифметическое среди элементов массива [1, 2, 5, 3, 2]: " << getMasAVG(mas1, 5) << endl;
	cout << "Среднее арифметическое среди элементов массива [2.8, 3.6, 4.1, 13.2, 16.4, 9.3]: " << getMasAVG(mas2, 6) << endl;
	cout << "Среднее арифметическое среди элементов массива ['a', 'b', 'c', 'd']: " << getMasAVG(mas3, 4) << endl;

	
	fptr f = testf;        
	cout << "\nНахождение корня уравнения 3*sin(sqrt(x))+0.35*x-3.8 = 0 методом итераций на отрезке [2;3]: ";
	cout << root(f, 2, 3, -2, 0.000001) << endl;
	cout << "Точное значение корня уравнения 3*sin(sqrt(x))+0.35*x-3.8 = 0 на отрезке [2;3]: 2.2985";
	return 0;
}