/* 1. Описать структуру с именем MARSH, содержащую следующие поля:
• название начального пункта маршрута;
• название конечного пункта маршрута;
• номер маршрута.
4. Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив, состоящий из восьми элементов
типа MARSH; записи должны быть упорядочены по номерам маршрутов;
• вывод на экран информации о маршруте, номер которого введен с
клавиатуры;
• если таких маршрутов нет, выдать на дисплей соответствующее
сообщение */

#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

struct marsh
 {
  char *begst;
  char *term;
  int numer;
};


marsh trafic[8];


void main()
{
	setlocale(LC_ALL,"Rus");
	for(int i=1; i<=8; i++)
	{
		trafic[i].begst = (char*)malloc(30*sizeof(char));
		trafic[i].term = (char*)malloc(30*sizeof(char));
	}

      for(int i = 1; i <= 8 ; i++)
        {
                cout << "Маршрут номер:  " << i <<"\n";
				trafic[i].numer = i;
				cout<< "Название начального пункта маршрута: ";
                cin >> trafic[i].begst;
                cout << "Конечного пункта: ";
                cin >> trafic[i].term;
        }

	  cout << "Введите название пункта: ";
	  char *naz;
	  naz=(char*)malloc(30*sizeof(char));
	  cin >>naz;

	  int k=0;
	  for (int i=1; i<=8; i++)
	  {
		  if ( (strcmp(trafic[i].begst, naz) ==0) || (strcmp(trafic[i].term, naz) ==0))
		  {		
			  cout << "Маршрут номер:  " << trafic[i].numer <<"\n";
			  cout << "Название начального пункта маршрута: " << trafic[i].begst<< "\n";
			  cout << "Конечного пункта: " << trafic[i].term << "\n";
		  k++;
		  }
		  
	  }
	  if(k==0) cout << "Таких маршрутов нет\n";