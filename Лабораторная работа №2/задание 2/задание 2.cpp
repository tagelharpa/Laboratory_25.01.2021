#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru"); // Врубаю русский язык
	int sum = 0; // Наш счетчик 
	for (int i = 3; i <= 200; i++) // От 3 до 200 как по заданию 
	{
		if (i % 3 == 0) // Если i кратно 3 то
			sum = sum + i; // Прибавляем к счетчику 
}
	cout << "количество кратное 3  и меньшее 200: " << sum << endl;  // Выводим результат на экран ))) 
	return 0;
}