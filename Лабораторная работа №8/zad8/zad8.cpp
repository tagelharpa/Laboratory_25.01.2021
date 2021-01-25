#include "point.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	linked_list_point* linked_list = NULL; //Указатель на однонаправленный список
	doubly_linked_list_point* doubly_linked_list = NULL; //Указатель на двунаправленный список
	tree_point* balanced_tree = NULL; //Указатель на идеально сбалансированное дерево
	tree_point* search_tree = NULL; //Указатель на дерево поиска
	int choice;
	do
	{
		cout << endl;
		cout << "1. Формирование однонаправленного списка\n";
		cout << "2. Печать однонаправленного списка\n";
		cout << "3. Удаление из однонаправленного списка всех элементов с четными полями\n";
		cout << "4. Удаление однонаправленного списка из памяти\n";
		cout << "5. Формирование двунаправленного списка\n";
		cout << "6. Печать двунаправленного списка\n";
		cout << "7. Добавление в двунаправленный список элемента с заданным номером\n";
		cout << "8. Удаление двунаправленного списка из памяти\n";
		cout << "9. Формирование идеально сбалансированного бинарного дерева\n";
		cout << "10. Печать идеально сбалансированного бинарного дерева\n";
		cout << "11. Найти количество элементов в бинарном дереве с заданным ключом\n";
		cout << "12. Преобразовать идеально сбалансированное дерево в дерево поиска\n";
		cout << "13. Печать дерева поиска\n";
		cout << "14. Выход\n";

		cin >> choice;

		switch (choice)
		{
		case 1: linked_list = make_linked_list(); break;
		case 2: print_linked_list(linked_list); break;
		case 3: linked_list = process_linked_list(linked_list); break;
		case 4: linked_list = delete_linked_list(linked_list); break;
		case 5: doubly_linked_list = make_doubly_linked_list(); break;
		case 6: print_doubly_linked_list(doubly_linked_list); break;
		case 7: doubly_linked_list = add_element_to_list(doubly_linked_list); break;
		case 8: doubly_linked_list = delete_doubly_linked_list(doubly_linked_list); break;
		case 9: balanced_tree = make_balanced_tree(); break;
		case 10: print_LKP(balanced_tree); break;
		case 11: print_number_of_elemets(balanced_tree); break;
		case 12: search_tree = make_search_tree(balanced_tree); break;
		case 13: print_LKP(search_tree); break;
		}

	} while (choice != 14); //выход

	return 0;
}

