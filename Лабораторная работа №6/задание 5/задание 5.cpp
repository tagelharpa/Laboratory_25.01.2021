#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int z = 0;
	string s;       
	char buf[255];  
	

	cout << "Введите предложение : ";
	gets_s(buf);      
	s = buf;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' ||  s[i] == '.')
		{
			s.erase(i, 1);
			i--;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		
		if (s[i] ==s[s.length() - 1 - i]) 
		{
			z++;
         }
        }
	if (z == s.length())
		cout << " ваше предложение палиндром-бом-бом))) " << endl;
	else
		cout << "ваше предложение не палиндром, эх! " << endl;












}