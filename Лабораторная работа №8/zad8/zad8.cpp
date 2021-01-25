#include "point.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	linked_list_point* linked_list = NULL; //��������� �� ���������������� ������
	doubly_linked_list_point* doubly_linked_list = NULL; //��������� �� ��������������� ������
	tree_point* balanced_tree = NULL; //��������� �� �������� ���������������� ������
	tree_point* search_tree = NULL; //��������� �� ������ ������
	int choice;
	do
	{
		cout << endl;
		cout << "1. ������������ ����������������� ������\n";
		cout << "2. ������ ����������������� ������\n";
		cout << "3. �������� �� ����������������� ������ ���� ��������� � ������� ������\n";
		cout << "4. �������� ����������������� ������ �� ������\n";
		cout << "5. ������������ ���������������� ������\n";
		cout << "6. ������ ���������������� ������\n";
		cout << "7. ���������� � ��������������� ������ �������� � �������� �������\n";
		cout << "8. �������� ���������������� ������ �� ������\n";
		cout << "9. ������������ �������� ����������������� ��������� ������\n";
		cout << "10. ������ �������� ����������������� ��������� ������\n";
		cout << "11. ����� ���������� ��������� � �������� ������ � �������� ������\n";
		cout << "12. ������������� �������� ���������������� ������ � ������ ������\n";
		cout << "13. ������ ������ ������\n";
		cout << "14. �����\n";

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

	} while (choice != 14); //�����

	return 0;
}

