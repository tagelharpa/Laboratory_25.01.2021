#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
using namespace std;


void main()
{
	int size = 0;

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	cout << " Введи количество элементов массива  : ";
	cin >> size;
	int *array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 1000;
		cout << array[i] << endl;

	}
	cout << "Размер массива на данный момент) " << sizeof(array) * size << endl;
	cout << endl;
	int k, b;
	cout << "Введи номер который хочешь удалить) : ";
	cin >> k;
	cout << "Массив без " << k << " элемента: ";
	for (int i = 0; i < size - 1; i++)
	{
		if (i >= k - 1)
		{
			b = array[i];
			array[i] = array[i + 1];
			array[i + 1] = b;

		}
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Чётные члены ряда:\n";
	int neven = 0;
	for (int i = 0; i < size - 1; i++) {
		if (array[i] % 2 == 0)
		{
			cout << array[i] << " ";
			neven++;
		}
	}
	int *array2 = new int[size + neven - 1];
	k = 0;
	for (int i = 0; i < size - 1; i++) {
		array2[k++] = array[i];
		if (array[i] % 2 == 0)
		{
			array2[k++] = 0;
		}
	}

	cout << "\nМассив с добавленным 0 после каждого четного элемента массива:\n";
	for (int i = 0; i < size + neven - 1; i++)
	{
		cout << array2[i] << endl;

	}

	cout << endl;
}