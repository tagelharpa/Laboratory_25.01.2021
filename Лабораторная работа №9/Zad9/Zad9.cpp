#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

//Объявление структуры абитуриент
struct entrant
{
	char name[50];          
	int year_of_birth;      
	int exam_scores[3];     
	float avg_cert_score;     

};


int input_entrants(entrant*& entrants)
{
	int n;
	cout << "Number of entrants? ";
	cin >> n;

	entrants = new entrant[n];
	for (int i = 0; i < n; i++)
	{
		cin.ignore(); 
		cout << "name? ";
		cin.getline(entrants[i].name, 50);
		cout << "year of birth? ";
		cin >> entrants[i].year_of_birth;
		cout << "3 exam scores? ";
		cin >> entrants[i].exam_scores[0] >> entrants[i].exam_scores[1] >> entrants[i].exam_scores[2];
		cout << "avg cert score? ";
		cin >> entrants[i].avg_cert_score;
	}
	return n;
}


void save_file_c(const char* fname, const entrant* entrants, int n)
{
	FILE *f;   
	f = fopen(fname, "w");

	
	for (int i = 0; i < n; i++)
	{
		fputs(entrants[i].name, f);
		fprintf(f, "\n%d %d %d %d %f\n", entrants[i].year_of_birth, entrants[i].exam_scores[0], entrants[i].exam_scores[1], entrants[i].exam_scores[2], entrants[i].avg_cert_score);
	}
	fclose(f);  
	return;
}


void print_file_c(const char* fname)
{
	entrant ent;  //Структура 
	FILE *f;    //Указатель 
	//открыть для чтения
	f = fopen(fname, "r");

	
	int i = 0;
	while (!feof(f)) 
	{
		
		fgets(ent.name, 50, f);
		fscanf(f, "%d %d %d %d %f\n", &ent.year_of_birth, &ent.exam_scores[0], &ent.exam_scores[1], &ent.exam_scores[2], &ent.avg_cert_score);

		
		i++;
		printf("Entrant %d:\n", i);
		printf("\tname: %s", ent.name);
		printf("\texam scores: %d %d %d\n", ent.exam_scores[0], ent.exam_scores[1], ent.exam_scores[2]);
		printf("\tavg cert score: %f\n", ent.avg_cert_score);
	}

	fclose(f); 
	return;
}


void del_record_c(const char* fname, int x)
{
	FILE *f;
	FILE*temp;

	
	f = fopen(fname, "r");
	
	temp = fopen("temp", "w");

	entrant ent;

	
	int i = 0;
	while (!feof(f))  
	{
		
		fgets(ent.name, 50, f);
		fscanf(f, "%d %d %d %d %f\n", &ent.year_of_birth, &ent.exam_scores[0], &ent.exam_scores[1], &ent.exam_scores[2], &ent.avg_cert_score);

		if (i != x)
		{
			
			fputs(ent.name, temp);
			fprintf(temp, "%d %d %d %d %f\n", ent.year_of_birth, ent.exam_scores[0], ent.exam_scores[1], ent.exam_scores[2], ent.avg_cert_score);
		}
		i++;
	}
	fclose(f);
	fclose(temp);
	remove(fname);
	rename("temp", fname);
	return;
}

//Добавляет к записей в начало файла в стиле С
void add_entrants_c(const char* fname, const entrant* entrants, int k)
{
	
	save_file_c("temp", entrants, k);
	FILE *f;//исходный файл
	FILE*temp;//вспомогательный файл

	
	f = fopen(fname, "r");
	
	temp = fopen("temp", "a+");

	entrant ent;

	//считываем данные из исходного файла в буфер
	while (!feof(f))  //пока не достигнут конец файла
	{
		//Чтение данных из файла в структуру
		fgets(ent.name, 50, f);
		fscanf(f, "%d %d %d %d %f\n", &ent.year_of_birth, &ent.exam_scores[0], &ent.exam_scores[1], &ent.exam_scores[2], &ent.avg_cert_score);

		
		fputs(ent.name, temp);
		fprintf(temp, "%d %d %d %d %f\n", ent.year_of_birth, ent.exam_scores[0], ent.exam_scores[1], ent.exam_scores[2], ent.avg_cert_score);
	}
	fclose(f);
	fclose(temp);
	remove(fname);
	rename("temp", fname);//переименовываем временный файл
	return;
}


void save_file_cpp(const char* fname, const entrant* entrants, int n)
{
	//открыть для записи
	ofstream f(fname);

	//запись элементов массива структур entrants в файл
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			f << endl;
		f << entrants[i].name << endl;
		f << entrants[i].year_of_birth << " ";
		f << entrants[i].exam_scores[0] << " " << entrants[i].exam_scores[1] << " " << entrants[i].exam_scores[2] << " ";
		f << entrants[i].avg_cert_score;
	}
	f.close();  //Закрываем файл
	return;
}


void print_file_cpp(const char* fname)
{
	entrant ent;  //Структура для чтения данных
	//открыть для чтения
	ifstream f(fname);

	
	int i = 0;
	string s;
	while (!f.eof())  
	{
		
		f.getline(ent.name, 50);
		f >> ent.year_of_birth >> ent.exam_scores[0] >> ent.exam_scores[1] >> ent.exam_scores[2] >> ent.avg_cert_score;
		f.ignore(); 
		i++;
		cout << "Entrant " << i << ":\n";
		cout << "\tname: " << ent.name << endl;
		cout << "\texam scores: " << ent.exam_scores[0] << " " << ent.exam_scores[1] << " " << ent.exam_scores[2] << endl;
		cout << "\tavg cert score: " << ent.avg_cert_score << endl;
	}
	f.close();  //Закрываем файл
	return;
}

//удаляет из файла запись с указанным номером в стиле С++
void del_record_cpp(const char* fname, int x)
{
	
	ifstream f(fname);
	
	ofstream temp("temp");

	entrant ent;

	
	int i = 0, j = 0;
	while (!f.eof())  
	{
		//Чтение данных из файла в структуру
		f.getline(ent.name, 50);
		f >> ent.year_of_birth >> ent.exam_scores[0] >> ent.exam_scores[1] >> ent.exam_scores[2] >> ent.avg_cert_score;
		f.ignore(); // удаляем символ новой строки из файлового потока

		if (i != x)
		{
			
			if (j > 0)
				temp << endl;
			temp << ent.name << endl;
			temp << ent.year_of_birth << " ";
			temp << ent.exam_scores[0] << " " << ent.exam_scores[1] << " " << ent.exam_scores[2] << " ";
			temp << ent.avg_cert_score;
			j++;
		}
		i++;
	}
	f.close();
	temp.close(); 
	remove(fname);
	rename("temp", fname);
	return;
}


void add_entrants_cpp(const char* fname, const entrant* entrants, int k)
{

	save_file_cpp("temp", entrants, k);
	
	ifstream f(fname);
	
	ofstream temp("temp", ios::app);

	entrant ent;
	
	int i = 0;
	while (!f.eof())  
	{
		//Чтение данных из файла в структуру
		f.getline(ent.name, 50);
		f >> ent.year_of_birth >> ent.exam_scores[0] >> ent.exam_scores[1] >> ent.exam_scores[2] >> ent.avg_cert_score;
		f.ignore(); // удаляем символ новой строки из файлового потока

		//дозаписываем данные из буфера во временный файл
		temp << endl << ent.name << endl;
		temp << ent.year_of_birth << " ";
		temp << ent.exam_scores[0] << " " << ent.exam_scores[1] << " " << ent.exam_scores[2] << " ";
		temp << ent.avg_cert_score;
	}
	f.close();//закрываем исходный файл
	temp.close(); 
	remove(fname);
	rename("temp", fname);
	return;
}


int main()
{
	
	const char* filename_c = "entrants_c.txt";
	const char* filename_cpp = "entrants_cpp.txt";

	
	entrant* entrants = 0;
	//Массив дополнительных записей
	entrant* add_entrants = 0;
	int x;

	int n = input_entrants(entrants);  //Ввод массива абитуриентов
	
	save_file_c(filename_c, entrants, n); 
	print_file_c(filename_c); 
	cout << "Number to delete? ";
	cin >> x;
	del_record_c(filename_c, x);   
	cout << "Record " << x << " deleted\n";
	cout << "Additional entrants:\n";
	int k = input_entrants(add_entrants); //Ввод дополнительных абитуриентов
	add_entrants_c(filename_c, add_entrants, k); 
	print_file_c(filename_c);  

	
	cout << "\n\nC++style\n";
	save_file_cpp(filename_cpp, entrants, n); 
	print_file_cpp(filename_cpp);  
	cout << "Number to delete? ";
	cin >> x;
	del_record_cpp(filename_cpp, x);  
	cout << "Record " << x << " deleted\n";
	add_entrants_cpp(filename_cpp, add_entrants, k); 
	print_file_cpp(filename_cpp);  

	return 0;
}
