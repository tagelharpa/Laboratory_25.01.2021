#include <iostream>
#include <cstring>

using namespace std;

//���� ������������ ������
struct linked_list_point
{
	int data;	    //�������������� ����
	linked_list_point* next;	//�������� ����
};

//���� ���������������� ������
struct doubly_linked_list_point
{
	char *key;//�������� ���� � ������������ ������
	doubly_linked_list_point *next;//��������� �� ��������� �������
	doubly_linked_list_point *pred;//��������� �� ���������� �������
};

//���� ��������� ������
struct tree_point
{
	char key;//�������������� ����
	tree_point *left;//����� ������ ���������
	tree_point *right;//����� ������� ���������
};



//�������� ����������������� ������
//���������� � �����
linked_list_point* make_linked_list()
{
	int n;
	cout << "������� ���������� ��������� � ����������������  ������: ";
	cin >> n;
	if (n <= 0)
	{
		return 0;
	}
	linked_list_point* beg;//��������� �� ������ �������
	linked_list_point* p, *r;//��������������� ���������
	beg = new(linked_list_point);//�������� ������ ��� ������ �������
	cout << "\n?";
	cin >> beg->data;//������ �������� ��������������� ����
	beg->next = 0;//�������� �������� ����
//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	for (int i = 0; i < n - 1; i++)
	{
		r = new(linked_list_point);//������� ����� �������
		cout << "\n?";
		cin >> r->data;
		r->next = 0;
		p->next = r;//��������� p � r
		//������ �� r ��������� p (��������� �������)
		p = r;
	}
	return beg;//���������� beg ��� ��������� �������
}

//������ ����������������� ������
void print_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;//������ ������
	if (p == 0)
		cout << "���� ����";

	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//������� � ���������� ��������
	}
	cout << endl;
}

//�������� �������� �� ������������ ������
linked_list_point* del_linked_list_point(linked_list_point*beg, linked_list_point*p)
{
	if (p == beg)//�������� ������� ��������
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//�������� �� ������ �� �������� ������ next �������� ����� ��������� �� ������� p ��� �� ����� ������
	linked_list_point* r = beg;
	while (r->next && r->next != p)
		r = r->next;
	//���� ������ �������� � ������ ���, �� ���������� ��������� �� ������ ������ � �������
	if (r->next == 0) return beg;

	r->next = p->next;//��������� ���������� � ����������� ������������ p ��������
	delete p;//������� ������� p �� ������
	return beg;
}

//�������� �� ������������ ������ ���� ��������� � ������� ��������������� ������
//������������ ��������� �� ������ ����������� ������
linked_list_point* process_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;//������ ������
	linked_list_point* r;    //��������� ���������� ��� �������� ���������� �������� ������
	while (p != 0)
	{
		r = p->next;                   //���������� ��������� �������
		if (p->data % 2 == 0)              // ���� �������������� ���� �������� ������, �� ������� ���
			beg = del_linked_list_point(beg, p);
		p = r;//������� � ���������� ��������
	}
	cout << "��� �������� � ������� ��������������� ������ �� ������ �������\n";
	return beg;
}

//�������� ����������������� ������ �� ������
linked_list_point* delete_linked_list(linked_list_point* beg)
{
	linked_list_point* p = beg;  //������ ������
	while (p != 0)              //���� � ������ ���� ��������
	{
		beg = p->next;       //�������� ��������� �������
		delete p;            //������� �������
		p = beg;               //��������� � ���������� ��������
	}
	cout << "���������������� ������ ������ �� ������\n";
	return NULL;
}

//�������� ������ �������� ���������������� ������
doubly_linked_list_point* make_doubly_linked_list_point()
{
	doubly_linked_list_point*p = new(doubly_linked_list_point);
	p->next = 0; p->pred = 0;//�������� ���������
	char s[50];
	cout << "\n������� ������: ";
	cin >> s;
	p->key = new char[strlen(s) + 1];//��������� ������ ��� ������
	strcpy(p->key, s);
	return p;
}

//�������� ���������������� ������
doubly_linked_list_point* make_doubly_linked_list()
{
	int n;
	cout << "������� ���������� ��������� � ���������������� ������: ";
	cin >> n;
	if (n <= 0)
	{
		return 0;
	}
	doubly_linked_list_point *p, *beg, *last;
	beg = make_doubly_linked_list_point();//������� ������ �������
	last = beg;                      //������ ������� �������� � ���������, ����� �� ����
	for (int i = 1; i < n; i++)
	{
		p = make_doubly_linked_list_point();//������� ���� �������
		//���������� �������� � ����� ������, ����� last
		last->next = p; 
		p->pred = last; //��������� � � ��������� ���������
		last = p;// p ���������� ��������� ��������� ������
	}
	return beg;
}

//������ ���������������� ������
void print_doubly_linked_list(doubly_linked_list_point* beg)
{
	doubly_linked_list_point* p = beg;//������ ������
	if (p == 0)
		cout << "���� ����";

	while (p != 0)
	{
		cout << p->key << "\t";
		p = p->next;//������� � ���������� ��������
	}
	cout << endl;
}

//���������� � ��������������� ������ �������� � �������� �������
doubly_linked_list_point* add_element_to_list(doubly_linked_list_point* beg)
{
	int k;
	cout << "������� ����� (��������� � ����) �������� ��� ���������� � ��������������� ������: ";
	cin >> k;
	if (k < 0)
	{
		cout << "����� �������� �� ����� ���� �������������\n";
		return beg;
	}
	doubly_linked_list_point* r = make_doubly_linked_list_point();//������� ���� �������
	if (k == 0)     //������� ������� � ������ ������
	{
		r->next = beg;//��������� r � ������ ���������
		beg->pred = r;//��������� ������ ������� � r
		beg = r;// r ���������� ������ ��������� ������
		return beg;
	}
	doubly_linked_list_point* p = beg;//������ ������
	int num = 0;
	while (p != 0 && num < k - 1)   //��������������� ����� ������ �������� ��� �� ���� ������� ����� ���, ��� ����� ��������
	{
		p = p->next;//������� � ���������� ��������
		num++;
	}
	if (p == 0)
		cout << "�������� �� ���������. � ������ ����� " << num << " ���������\n";
	else
	{
		//���������� �������� � ������ ����� p
		r->next = p->next; //��������� ����� ������� � ���, ��� ��� ����� p
		p->next = r;//��������� � � ����� ���������
		r->pred = p;//��������� ����� ������� � p
	}
	return beg;
}

//�������� ���������������� ������ �� ������
doubly_linked_list_point* delete_doubly_linked_list(doubly_linked_list_point* beg)
{
	doubly_linked_list_point* p = beg;  //������ ������
	while (p != 0)              //���� � ������ ���� ��������
	{
		beg = p->next;       //�������� ��������� �������
		delete[] p->key;     //�������� ������ ���������� ��� ������ � ������� ��������
		delete p;            //������� ������� �������
		p = beg;               //��������� � ���������� ��������
	}
	cout << "��������������� ������ ������ �� ������\n";
	return NULL;
}

//���������� �������� ����������������� ������
tree_point* make_balanced_tree(int n = -1)
{
	if (n < 0)   //�������� ������� �������� ������
	{
		int k;
		cout << "������� ���������� ��������� � �������� ������: ";
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
	cout << "������� ������: ";
	cin >> r->key;
	r->left = make_balanced_tree(nl);
	r->right = make_balanced_tree(nr);
	return r;
}

//����� ������ �� ����� � ������� �����-������-������
void print_LKP(tree_point* tree)
{
	if (!tree)
		return;
	print_LKP(tree->left);
	cout << tree->key << " ";
	print_LKP(tree->right);
	return;
}

//������� ��������� ���������� ��������� � �������� ������ � ������
int find_number_of_elemets(tree_point* tree, char ch, int n = 0)
{
	if (!tree)   //� ������ ��� ���������
		return n;
	if (tree->key == ch)
		n++;
	n = find_number_of_elemets(tree->left, ch, n);   //���� ������� � �������� ������ � ����� ���������
	n = find_number_of_elemets(tree->right, ch, n);   //���� ������� � �������� ������ � ������ ���������
	return n;
}

//������� ��������� �� ����� ���������� ��������� � �������� ������ � ������
void print_number_of_elemets(tree_point* tree)
{
	char ch;
	cout << "������� ���� ��� ������ � ������: ";
	cin >> ch;
	int n;
	n = find_number_of_elemets(tree, ch);
	cout << "���������� ��������� � �������� ������: " << n << endl;
	return;
}

//�������� ������� �������� ������ ������
tree_point* first(char ch)//������������ ������� �������� ������
{
	tree_point* p = new tree_point;
	p->key = ch;
	p->left = 0;
	p->right = 0;
	return p;
}

//���������� �������� � ������ ������
//������������ ��������� �� ������ ������ � ����������� ���������
tree_point* add_to_search_tree(tree_point* root, char ch)
{
	tree_point* p = root;//������ ������
	if (p == NULL)  //�������� ������� �������� ������
	{
		p = first(ch);
		return p;
	}
	tree_point* r = NULL;

	//���� ��� �������� ������������� �������� d � ������
	bool ok = false;
	while (p && !ok)
	{
		r = p;
		if (ch == p->key)
			ok = true;//������� ��� ����������
		else
			if (ch < p->key)
				p = p->left;//����� � ����� ���������
			else
				p = p->right;//����� � ������ ���������
	}
	if (ok)
		return root;//������� (��� ���� � ������), �� ���������

	//������� ����
	tree_point* New_point = new tree_point();//�������� ������
	New_point->key = ch;
	New_point->left = 0;
	New_point->right = 0;

	// ���� ch<r->key, �� ��������� ��� � ����� ���������
	if (ch < r->key)
		r->left = New_point;
	// ���� ch>r->key, �� ��������� ��� � ������ ���������
	else
		r->right = New_point;
	return root;
}

//�������, ����������������� �������� ���������������� ������ � ������ ������
tree_point* make_search_tree(tree_point* balanced_tree, tree_point* search_tree = NULL)
{
	if (!balanced_tree)
		return search_tree;
	search_tree = add_to_search_tree(search_tree, balanced_tree->key);   //��������� � ������ ������ ���� �������� ���� �������� ����������������� ������
	search_tree = make_search_tree(balanced_tree->left, search_tree);    //������ ������ ������ �� ������ ���������
	search_tree = make_search_tree(balanced_tree->right, search_tree);   //������ ������ ������ �� ������� ���������
	return search_tree;
}
