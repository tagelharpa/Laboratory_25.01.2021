#include <iostream>
#include <cstring>

using namespace std;

int getWord(const char a[], int j, char word[])
{

	int i = 0;
	while (a[j] != '0')
	{
		word[i] = a[j];
		j++;
		i++;
	}
	word[i] = '\0';
	j++;
	return j;

}

int main()
{
	int const n = 3;
	const char* mas[] = { "123023402303450", "234450234567010", "234455677670450" }; 
	char res[60] = "";                                                         
	char word[60] = "";                                                        
	for (int i = 0; i < n; i++)                                                
	{
		int j = 0;
		int len = strlen(mas[i]);   
		strcpy_s(res, "(");            
		while (j < len)   
		{
			j = getWord(mas[i], j, word);    
			strcat_s(res, word);                 
			if (j < len)
				strcat_s(res, ",");
		}
		strcat_s(res, ") ");
		cout << res;
	}

	return 0;
}
