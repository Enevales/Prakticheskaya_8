/*1. Описать структуру с именем AEROFLOT, содержащую следующие ноля:
• название пункта назначения рейса;
• номер рейса;
• тип самолета.
2. Написать программу, выполняющую следующие действия:
• ввод с клавиатуры данных в массив, состоящий из семи элементов типа
AEROFLOT; записи должны быть размещены в алфавитном порядке по
названиям пунктов назначения;
• вывод на экран пунктов назначения и номеров рейсов, обслуживаемых
самолетом, тип которого введен с клавиатуры;
• если таких рейсов нет, выдать на дисплей соответствующее сообщение. */

#include <iostream>
#include <string>
#include <clocale>

using namespace std;

struct Aeroflot
{
	string pynkt;// пункт назначения
	int num_r;// номер рейса
	string type;// тип самолета
};

void vvod_dan(Aeroflot *a,const int & k)
{

	for(int i(0);i<k;++i)
	{
		cout<<"ВВедите пункт назначения:";
		cin>>a[i].pynkt;
		cout<<"ВВедите номер рейса:";
		cin>>a[i].num_r;
		cout<<"ВВедите тип самолета:";
		cin>>a[i].type;
	}
}

// сортировка по возрастанию номеров рейса
void sort_nomr(Aeroflot *a,const int &k)
{
	for(int i(k-1);i>=0;i--)
		for(int j(0);j<i;j++)
			if(a[j].num_r>a[j+1].num_r)
				swap(a[j].num_r,a[j+1].num_r);
}

void sravn(Aeroflot *a,const int &k,string &s)
{

	int n(0);
	for(int i(0);i<k;++i)
	{
		if(a[i].pynkt==s)cout<<a[i].num_r<<" "<<a[i].type<<endl;
		else n++;

	}
	if(n==k)cout<<"Таких рейсов нет\n";

}

int main()
{	setlocale(LC_CTYPE,"rus");

	Aeroflot *air;
	const int kol=7;
	// выделяем место в памяти под 7 структур
	air=new Aeroflot[kol];

	vvod_dan(air,kol);
	sort_nomr(air,kol);
	//строка с которой будем сравнивать
	string str;
	cout<<endl<<"Введите пункт назначения:";
	cin>>str;
	sravn(air,kol,str);
	delete []air;
	return 0;
}