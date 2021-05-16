#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;
struct Pen
{
	string name, color;
	void Get_name()
	{
		string na, col;
		string names[] = { "Stabila", "EricCrauser" };
		string colors[] = { "Синий" , "Желтый", "Розовый", "Черный", "Белый" };
		
		name = names[rand() % 2];
		color = colors[rand() % 5];
		// cout << "Введите название фирмы ручки: ";
		// cin >> na;
		// name = na;
		// cout << "Введите цвет ручки: ";
		// cin >> col;
		// color = col;
	}
	void Print()
	{
		cout << "Название ручки: " << name << endl;
		cout << "Цвет ручки: " << color << endl;
	}
};
vector<Pen> CreateArray(int size)
{
	vector<Pen> res;
	for (int i = 0; i < size; i++)
	{
		Pen newEl;
		newEl.Get_name();
		res.push_back(newEl);
	}
	return res;
}
void PrintArray(vector<Pen> pens)
{
	if (pens.size() < 1)
	{
		cout << "Список пуст" << endl;
		return;
	}
	for (int i = 0; i < pens.size(); i++)
	{
		cout << endl << "Элемент " << i + 1 << endl;
		pens[i].Print();
	}
}

void Shell_sort(vector<Pen>& list)
{

	int size = list.size();
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			for (int j = i; j >= step; j -= step)
			{
				if (list[j].color < list[j - step].color)
				{
					Pen temp = list[j];
					list[j] = list[j - step];
					list[j - step] = temp;
				}
			}
		}
	}
}
void Quick_sort(vector<Pen>& list, int left = NULL, int right = NULL)
{
	left = left != NULL ? left : 0;
	right = right != NULL ? right : list.size() - 1;

	int i = left;
	int j = right;
	string pivot = list[(i + j) / 2].color;

	do
	{
		while (list[i].color < pivot)
		{
			i++;
		}
		while (list[j].color > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			Pen tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
			i++;
			j--;
		}
		

	} while (i <= j);

	if (j > left)
	{
		Quick_sort(list, left, j);
	}
	if (i < right)
	{
		Quick_sort(list, i, right);
	}
}

int main()
{
	system("color F0");
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	do
	{	
		cout << "Введите кол-во ручек в списке: ";
		cin >> size;
	} while (size <= 0);
	vector<Pen> pensMas;
	pensMas = CreateArray(size);
	PrintArray(pensMas);
	
	int vvod;
	cout << "1 - Сортировка методом Шелла " << endl;
	cout << "2 - Сортировка методом Хоара " << endl;
	cin >> vvod;
	if (vvod == 1)
	{
		cout << "Отсортированный список: " << endl;
		Shell_sort(pensMas);
		PrintArray(pensMas);
	}
	else if (vvod == 2)
	{
		cout << "Отсортированный список: " << endl;
		Quick_sort(pensMas);
		PrintArray(pensMas);
	}
	else
	{
		cout << "Введено некорректное значение:(" << endl;
	}

	return 0;
}