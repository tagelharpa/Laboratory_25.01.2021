#include <stdio.h>
#include <iostream>

using namespace std;


struct dayTemp
{
	int dayNum;             
	double temp;           
	bool isDeleted;         
};

struct dayTempPoint
{
	dayTemp data;           
	dayTempPoint* next;     
};


dayTempPoint* createPoint()
{
	dayTempPoint* p = new dayTempPoint;
	cout << "\nНомер дня:";
	cin >> p->data.dayNum;
	cout << "Температура:";
	cin >> p->data.temp;
	p->data.isDeleted = false;
	p->next = 0;
	return p;
}


dayTempPoint* makeLinkedList()
{
	int n;
	cout << "Введите количество элементов в новой БД: ";
	cin >> n;
	if (n <= 0)
	{
		return 0;
	}
	dayTempPoint* beg;
	dayTempPoint* p, *r;
	beg = createPoint();

   
	p = beg;
	for (int i = 0; i < n - 1; i++)
	{
		r = createPoint();
		p->next = r;
		
		p = r;
	}
	return beg;
}


dayTempPoint* readLinkedList(const char* fname)
{
	FILE *f;    
	
	f = fopen(fname, "rb");
	if (f == 0)
		return 0;
	dayTemp a;

	dayTempPoint* beg;
	dayTempPoint* p, *r;
	beg = new dayTempPoint;
	fread(&a, sizeof(dayTemp), 1, f);
	beg->data = a;
	beg->next = 0;
	 
	p = beg;
	fread(&a, sizeof(dayTemp), 1, f); 
	while (!feof(f))
	{
		r = new dayTempPoint;
		r->data = a;
		r->next = 0;
		p->next = r;
		
		p = r;
		fread(&a, sizeof(dayTemp), 1, f); 
	}
	fclose(f); 
	return beg;
}


void printLinkedList(dayTempPoint* beg)
{
	dayTempPoint* p = beg;

	int i = 1;
	while (p != 0)
	{
		if (!p->data.isDeleted) 
		{
			cout << i << ". день: " << p->data.dayNum << "\t" << "температура: " << p->data.temp << endl;
			i++;
		}
		p = p->next;
	}
	if (i == 1)
		cout << "Нет данных";
	cout << endl;
}


double getDeletedRatio(dayTempPoint* beg)
{
	
	double num = 0;
	double del = 0;
	dayTempPoint* p = beg;
	while (p)
	{
		num++;
		if (p->data.isDeleted)
			del++;
		p = p->next;
	}
	return del / num;
}

//Вычисление средней температуры за месяц
double getAvgTemp(dayTempPoint* beg)
{
	
	double num = 0;
	double tempSum = 0;
	dayTempPoint* p = beg;
	while (p)
	{
		if (p->data.isDeleted == false)
		{
			num++;
			tempSum += p->data.temp;
		}
		p = p->next;
	}
	return tempSum / num;
}


void printWarmDays(dayTempPoint* beg, double avgTemp)
{
	
	dayTempPoint* p = beg;
	int i = 1;
	while (p)
	{
		if (p->data.isDeleted == false && p->data.temp > avgTemp)
		{
			cout << i << ". день: " << p->data.dayNum << "\t" << "температура: " << p->data.temp << endl;
			i++;
		}
		p = p->next;
	}
	return;
}


void printColdDaysCount(dayTempPoint* beg)
{
	dayTempPoint* p = beg;
	bool wasNeg = false;  
	dayTempPoint* begDayPoint = NULL;  
	dayTempPoint* endDayPoint = NULL;  
	int days = 0;   
	int maxDays = 0; 
	int begDay = 0;  
	int endDay = 0;  
	while (p)
	{
		if (p->data.isDeleted == false && p->data.temp < 0)
		{
			if (wasNeg == false)  
			{
				begDayPoint = p;  //фиксируем начало отрезка
			}
			wasNeg = true;
			endDayPoint = p;  
		}
		if (p->data.isDeleted == false && p->data.temp >= 0)
		{
			if (wasNeg)  
			{
				if (begDayPoint && endDayPoint)
					days = endDayPoint->data.dayNum - begDayPoint->data.dayNum;
				if (days > maxDays)
				{
					maxDays = days;
					begDay = begDayPoint->data.dayNum;
					endDay = endDayPoint->data.dayNum;
				}

			}
			wasNeg = false;
		}
		if (p->next == NULL && wasNeg) 
		{
			if (begDayPoint && endDayPoint)
				days = endDayPoint->data.dayNum - begDayPoint->data.dayNum;
			if (days > maxDays)
			{
				maxDays = days;
				begDay = begDayPoint->data.dayNum;
				endDay = endDayPoint->data.dayNum;
			}
		}
		p = p->next;
	}
	if (maxDays == 0)
		cout << "Дней с отрицательными температурами не было\n";
	else
	{
		cout << "Максимальное количество дней с отрицательными температурами: " << maxDays << endl;
		cout << "с " << begDay << " по " << endDay << " день\n";
	}
	return;
}

//Сохранение списка в файл
void saveLinkedList(const char* fname, dayTempPoint* beg)
{
	bool notSaveDeleted = false;
	//Определим количество удаленных элементов. Если их больше половины, то их в файл не сохраняем
	if (getDeletedRatio(beg) > 0.5)
		notSaveDeleted = true;

	FILE *f;    
	
	f = fopen(fname, "wb");
	dayTemp a;//буфер для записи данных в файл
	dayTempPoint* p = beg;//начало списка

	while (p != 0)
	{
		if (notSaveDeleted && p->data.isDeleted)
		{
			p = p->next;
			continue;
		}
		a = p->data;
		fwrite(&a, sizeof(dayTemp), 1, f);
		p = p->next;
	}
	fclose(f);
}


dayTempPoint* findLinkedListPoint(dayTempPoint*beg, int num)
{
	dayTempPoint* p = beg;
	
	while (p && p->data.isDeleted == true)
		p = p->next;
	if (num == 1) //если ищем первый элемент
	{
		return p;
	}
	
	int i = 1;
	while (p && i != num)
	{
		p = p->next;
		if (p && p->data.isDeleted == false)  
			i++;
	}

	//возвращаем элемент p
	return p;
}

//поиск элемента по номеру дня
dayTempPoint* findLinkedListPointByDay(dayTempPoint*beg, int dayNum)
{
	dayTempPoint* p = beg;
	//проходим по списку до элемента счётчик i не будет равен num
	while (p && p->data.dayNum != dayNum)
	{
		p = p->next;
	}

	if (p->data.isDeleted)
		p = NULL;
	return p;
}


dayTempPoint* delLinkedListPoint(dayTempPoint*beg, int num)
{
	dayTempPoint* p = findLinkedListPoint(beg, num);
	if (p == 0)
	{
		cout << "Элемент с номером: " << num << " в списке отсутствует\n";
		return p;
	}
	//удаляем элемент p, точнее помечаем его как удаленный
	p->data.isDeleted = true;
	cout << "Элемент с номером: " << num << " удален\n";
	return p;
}


dayTempPoint* delLinkedListPointByDay(dayTempPoint*beg, int dayNum)
{
	dayTempPoint* p = findLinkedListPointByDay(beg, dayNum);

	
	if (p == 0)
	{
		cout << "Элемент с номером дня: " << dayNum << " в списке отсутствует\n";
		return p;
	}

	
	p->data.isDeleted = true;
	cout << "Элемент с номером дня: " << dayNum << " удален\n";
	return p;
}


void editLinkedListPoint(dayTempPoint*beg, int num, double temp)
{
	dayTempPoint* p = findLinkedListPoint(beg, num);
	if (p == 0)
	{
		cout << "Элемент с номером: " << num << " в списке отсутствует\n";
		return;
	}
	
	p->data.temp = temp;
	cout << "Элемент с номером: " << num << " изменен\n";
	return;
}


void editLinkedListPointByDay(dayTempPoint*beg, int dayNum, double temp)
{
	dayTempPoint* p = findLinkedListPointByDay(beg, dayNum);

	
	if (p == 0)
	{
		cout << "Элемент с номером дня: " << dayNum << " в списке отсутствует\n";
		return;
	}

	
	p->data.temp = temp;
	cout << "Элемент с номером дня: " << dayNum << " изменен\n";
	return;
}


dayTempPoint* addPointToBeg(dayTempPoint* beg, dayTempPoint* p)
{
	p->next = beg;
	return p;
}


void addPointToEnd(dayTempPoint* beg, dayTempPoint* p)
{
	dayTempPoint* r = beg;
	
	while (r->next)
		r = r->next;

	
	r->next = p;
	return;
}


dayTempPoint* addPointToPos(dayTempPoint* beg, dayTempPoint* p, int num)
{
	if (num == 1) //добавляем в начало
	{
		return addPointToBeg(beg, p);
	}
	dayTempPoint* r = findLinkedListPoint(beg, num - 1);  
	if (r == NULL) 
	{
		addPointToEnd(beg, p);
		return beg;
	}
	
	p->next = r->next;
	r->next = p;
	return beg;
}

int main()
{
	
	const char* filename = "base.dat";
	setlocale(LC_ALL, "");
	dayTempPoint* linked_list = readLinkedList(filename); 
	dayTempPoint* p = NULL;
	dayTempPoint* deletedPoint = NULL;

	int choice;
	int num;
	double temp;
	do
	{
		cout << endl;
		cout << "1. Создание БД\n";
		cout << "2. Вывод содержимого БД на экран\n";
		cout << "3. Удаление записи из БД по её номеру\n";
		cout << "4. Удаление записи из БД по номеру дня\n";
		cout << "5. Добавить запись в начало\n";
		cout << "6. Добавить запись в заданную позицию\n";
		cout << "7. Добавить запись в конец\n";
		cout << "8. Корректировка записи по её номеру\n";
		cout << "9. Корректировка записи с номером дня\n";
		cout << "10. Отмена последней операции удаления\n";
		cout << "11. Вывести дни, когда температура поднималась выше средней за месяц\n";
		cout << "12. Вывести максимальное количество дней, когда температура была ниже нуля\n";
		cout << "13. Сохранить изменения\n";
		cout << "14. Выход\n";

		cin >> choice;
		switch (choice)
		{
		case 1:
			linked_list = makeLinkedList();
			
			break;
		case 2:
			printLinkedList(linked_list);
			break;
		case 3:
			cout << "Введите номер элемента: ";
			cin >> num;
			deletedPoint = delLinkedListPoint(linked_list, num);
			break;
		case 4:
			cout << "Введите номер дня: ";
			cin >> num;
			deletedPoint = delLinkedListPointByDay(linked_list, num);
			break;
		case 5:
			p = createPoint();
			linked_list = addPointToBeg(linked_list, p);
			break;
		case 6:
			cout << "Введите номер позиции для добавление записи: ";
			cin >> num;
			p = createPoint();
			linked_list = addPointToPos(linked_list, p, num);
			break;
		case 7:
			p = createPoint();
			addPointToEnd(linked_list, p);
			break;
		case 8:
			cout << "Введите номер элемента: ";
			cin >> num;
			cout << "Введите новое значение температуры: ";
			cin >> temp;
			editLinkedListPoint(linked_list, num, temp);
			break;
		case 9:
			cout << "Введите номер дня: ";
			cin >> num;
			cout << "Введите новое значение температуры: ";
			cin >> temp;
			editLinkedListPointByDay(linked_list, num, temp);
			break;
		case 10:
			if (deletedPoint)
			{
				deletedPoint->data.isDeleted = false;
				cout << "Последняя операции удаления отменена\n";
			}
			else
				cout << "Последняя операции удаления отсутсвует\n";
			break;
		case 11:
			temp = getAvgTemp(linked_list);
			cout << "Средняя температура за месяц: " << temp << endl;
			cout << "Дни, когда температура была выше средней: \n";
			printWarmDays(linked_list, temp);
			break;
		case 12:
			printColdDaysCount(linked_list);
			break;
		case 13:
			saveLinkedList(filename, linked_list);
			cout << "Данные записаны в файл БД\n";
			break;
		}

	} while (choice != 14); 
	return 0;
}
