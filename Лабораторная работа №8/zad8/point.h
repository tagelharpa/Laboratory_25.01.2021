#include <iostream>
#include <cstring>

using namespace std;

//узел односвязного списка
struct linked_list_point
{
	int data;	    //информационное поле
	linked_list_point* next;	//адресное поле
};

//узел двунаправленного списка
struct doubly_linked_list_point
{
	char *key;//адресное поле – динамическая строка
	doubly_linked_list_point *next;//указатель на следующий элемент
	doubly_linked_list_point *pred;//указатель на предыдущий элемент
};

//узел бинарного дерева
struct tree_point
{
	char key;//информационное поле
	tree_point *left;//адрес левого поддерева
	tree_point *right;//адрес правого поддерева
};



//создание однонаправленного списка
//добавление в конец
linked_list_point* make_linked_list()
{
	int n;
	cout << "Введите количество элементов в однонаправленном  списке: ";
	cin >> n;
	if (n <= 0)
	{
		return 0;
	}
	linked_list_point* beg;//указатель на первый элемент
	linked_list_point* p, *r;//вспомогательные указатели
	beg = new(linked_list_point);//выделяем память под первый элемент
	cout << "\n?";
	cin >> beg->data;//вводим значение информационного поля
	beg->next = 0;//обнуляем адресное поле
//ставим на этот элемент указатель p (последний элемент)
	p = beg;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(linked_list_point);//создаем новый элемент
		cout << "\n?";
		cin >> r->data;
		r->next = 0;
		p->next = r;//связываем p и r
		//ставим на r указатель p (последний элемент)
		p = r;
	}
	return beg;//возвращаем beg как результат функции
}

//печать однонаправленного списка
void print_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;//начало списка
	if (p == 0)
		cout << "Лист пуст";

	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//переход к следующему элементу
	}
	cout << endl;
}

//удаление элемента из односвязного списка
linked_list_point* del_linked_list_point(linked_list_point*beg, linked_list_point*p)
{
	if (p == beg)//удаление первого элемента
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//проходим по списку до элемента ссылка next которого будет указывать на элемент p или до конца списка
	linked_list_point* r = beg;
	while (r->next && r->next != p)
		r = r->next;
	//если такого элемента в списке нет, то возвращаем указатель на начало списка и выходим
	if (r->next == 0) return beg;

	r->next = p->next;//связываем предыдущий и последующий относительно p элементы
	delete p;//удаляем элемент p из памяти
	return beg;
}

//удаление из односвязного списка всех элементов с четными информационными полями
//возвращается указатель на начало изменненого списка
linked_list_point* process_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;//начало списка
	linked_list_point* r;    //временная переменная для хранения следующего элемента списка
	while (p != 0)
	{
		r = p->next;                   //запоминаем следующий элемент
		if (p->data % 2 == 0)              // если информационное поле элемента четное, то удаляем его
			beg = del_linked_list_point(beg, p);
		p = r;//переход к следующему элементу
	}
	cout << "Все элементы с четными информационными полями из списка удалены\n";
	return beg;
}

//удаление однонаправленного списка из памяти
linked_list_point* delete_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;  //начало списка
	while (p != 0)              //пока в списке есть элементы
	{
		beg = p->next;       //получаем следующий элемент
		delete p;            //удаляем текущий
		p = beg;               //переходим к следующему элементу
	}
	cout << "Однонаправленный список удален из памяти\n";
	return NULL;
}

//создание одного элемента двунаправленного списка
doubly_linked_list_point* make_doubly_linked_list_point()
{
	doubly_linked_list_point*p = new(doubly_linked_list_point);
	p->next = 0; p->pred = 0;//обнуляем указатели
	char s[50];
	cout << "\nВведите строку: ";
	cin >> s;
	p->key = new char[strlen(s) + 1];//выделение памяти под строку
	strcpy(p->key, s);
	return p;
}

//создание двунаправленного списка
doubly_linked_list_point* make_doubly_linked_list()
{
	int n;
	cout << "Введите количество элементов в двунаправленного списке: ";
	cin >> n;
	if (n <= 0)
	{
		return 0;
	}
	doubly_linked_list_point *p, *beg, *last;
	beg = make_doubly_linked_list_point();//создаем первый элемент
	last = beg;                      //Первый элемент является и последним, когда он один
	for (int i = 1; i < n; i++)
	{
		p = make_doubly_linked_list_point();//создаем один элемент
		//добавление элемента в конец списка, после last
		last->next = p; 
		p->pred = last; //связываем р с последним элементом
		last = p;// p становится последним элементом списка
	}
	return beg;
}

//печать двунаправленного списка
void print_doubly_linked_list(doubly_linked_list_point* beg)
{
	doubly_linked_list_point* p = beg;//начало списка
	if (p == 0)
		cout << "Лист пуст";

	while (p != 0)
	{
		cout << p->key << "\t";
		p = p->next;//переход к следующему элементу
	}
	cout << endl;
}

//Добавление в двунаправленный список элемента с заданным номером
doubly_linked_list_point* add_element_to_list(doubly_linked_list_point* beg)
{
	int k;
	cout << "Введите номер (нумерация с нуля) элемента для добавления в двунаправленный список: ";
	cin >> k;
	if (k < 0)
	{
		cout << "Номер элемента не может быть отрицательным\n";
		return beg;
	}
	doubly_linked_list_point* r = make_doubly_linked_list_point();//создаем один элемент
	if (k == 0)     //вставим элемент в начало списка
	{
		r->next = beg;//связываем r с первым элементом
		beg->pred = r;//связываем первый элемент с r
		beg = r;// r становится первым элементом списка
		return beg;
	}
	doubly_linked_list_point* p = beg;//начало списка
	int num = 0;
	while (p != 0 && num < k - 1)   //останавливаемся когда список кончился или за один элемент перед тем, что нужно вставить
	{
		p = p->next;//переход к следующему элементу
		num++;
	}
	if (p == 0)
		cout << "Операция не выполнена. В списке всего " << num << " элементов\n";
	else
	{
		//добавление элемента в список после p
		r->next = p->next; //связываем новый элемент с тем, что шел после p
		p->next = r;//связываем р с новым элементом
		r->pred = p;//связываем новый элемент с p
	}
	return beg;
}

//удаление двунаправленного списка из памяти
doubly_linked_list_point* delete_doubly_linked_list(doubly_linked_list_point* beg)
{
	doubly_linked_list_point* p = beg;  //начало списка
	while (p != 0)              //пока в списке есть элементы
	{
		beg = p->next;       //получаем следующий элемент
		delete[] p->key;     //Удаление памяти выделенной под строку в текущем элементе
		delete p;            //удаляем текущий элемент
		p = beg;               //переходим к следующему элементу
	}
	cout << "Двунаправленный список удален из памяти\n";
	return NULL;
}

//построение идеально сбалансированного дерева
tree_point* make_balanced_tree(int n = -1)
{
	if (n < 0)   //создание первого элемента дерева
	{
		int k;
		cout << "Введите количество элементов в бинарном дереве: ";
		cin >> k;
		return make_balanced_tree(k);
	}
	tree_point*r;
	int nl, nr;
	if (n == 0)
		return NULL;

	nl = n / 2;
	nr = n - nl - 1;
	r = new tree_point;
	cout << "Введите символ: ";
	cin >> r->key;
	r->left = make_balanced_tree(nl);
	r->right = make_balanced_tree(nr);
	return r;
}

//вывод дерева на экран в порядке левое-корень-правое
void print_LKP(tree_point* tree)
{
	if (!tree)
		return;
	print_LKP(tree->left);
	cout << tree->key << " ";
	print_LKP(tree->right);
	return;
}

//функция находящая количество элементов с заданным ключом в дереве
int find_number_of_elemets(tree_point* tree, char ch, int n = 0)
{
	if (!tree)   //в дереве нет элементов
		return n;
	if (tree->key == ch)
		n++;
	n = find_number_of_elemets(tree->left, ch, n);   //ищем элемент с заданным ключом в левом поддереве
	n = find_number_of_elemets(tree->right, ch, n);   //ищем элемент с заданным ключом в правом поддереве
	return n;
}

//функция выводящая на экран количество элементов с заданным ключом в дереве
void print_number_of_elemets(tree_point* tree)
{
	char ch;
	cout << "Введите ключ для поиска в дереве: ";
	cin >> ch;
	int n;
	n = find_number_of_elemets(tree, ch);
	cout << "Количество элементов с заданным ключом: " << n << endl;
	return;
}

//создание первого элемента дерева поиска
tree_point* first(char ch)//формирование первого элемента дерева
{
	tree_point* p = new tree_point;
	p->key = ch;
	p->left = 0;
	p->right = 0;
	return p;
}

//Добавление элемента в дерево поиска
//Возвращается указатель на дерево поиска с добавленным элементом
tree_point* add_to_search_tree(tree_point* root, char ch)
{
	tree_point* p = root;//корень дерева
	if (p == NULL)  //создание первого элемента дерева
	{
		p = first(ch);
		return p;
	}
	tree_point* r = NULL;

	//флаг для проверки существования элемента d в дереве
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (ch == p->key)
			ok = true;//элемент уже существует
		else
			if (ch < p->key)
				p = p->left;//пойти в левое поддерево
			else
				p = p->right;//пойти в правое поддерево
	}
	if (ok)
		return root;//найдено (уже есть в дереве), не добавляем

	//создаем узел
	tree_point* New_point = new tree_point();//выделили память
	New_point->key = ch;
	New_point->left = 0;
	New_point->right = 0;

	// если ch<r->key, то добавляем его в левое поддерево
	if (ch < r->key)
		r->left = New_point;
	// если ch>r->key, то добавляем его в правое поддерево
	else
		r->right = New_point;
	return root;
}

//Функция, преобразовывающая идеально сбалансированное дерево в дерево поиска
tree_point* make_search_tree(tree_point* balanced_tree, tree_point* search_tree = NULL)
{
	if (!balanced_tree)
		return search_tree;
	search_tree = add_to_search_tree(search_tree, balanced_tree->key);   //добавляем в дерево поиска ключ текущего узла идеально сбалансированного дерева
	search_tree = make_search_tree(balanced_tree->left, search_tree);    //строим дерево поиска из левого поддерева
	search_tree = make_search_tree(balanced_tree->right, search_tree);   //строим дерево поиска из правого поддерева
	return search_tree;
}
