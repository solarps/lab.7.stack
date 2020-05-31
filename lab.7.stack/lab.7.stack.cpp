#include <iostream>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;


void firstlvl() 
{
	stack <double> Numbers;

	cout << "Введите кол-во чисел для ввода: " << endl;
	double size, a, max = 0;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		a = rand() % 100 * 0.1;

		Numbers.push(a);
		if (a > max)
		{
			max = a;
		}
	}

	cout << "Элементы в стеке: ";
	while (!Numbers.empty())
	{
		cout << ' ' << Numbers.top();
		Numbers.pop();
	}
	cout << endl << "Максимальное число в стеке: " << max << endl;
}

void secondlvl()
{
	queue <double> Numbers;
	double arr[3], sum = 0;

	Numbers.push(2.1);
	Numbers.push(2.1);
	Numbers.push(5.3);

	if (Numbers.empty())
	{
		cout << "Очередь пуста" << endl << endl;
	}
	else
	{
		cout << "Первые 3 числа очереди: ";

		for (int i = 0; i < 3;i++)
		{
			cout << Numbers.front() << " ";
			arr[i] = Numbers.front();
			Numbers.pop();
		}

		cout << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			Numbers.push(arr[i]);
		}
		Numbers.push(4.9);

		if (!Numbers.empty())
		{
			cout << "Числа очереди после добавление 4-ого элемента: ";

			for (int i = 0; i < 4; i++)
			{
				cout << Numbers.front() << " ";
				sum += Numbers.front();
				Numbers.pop();
			}

			cout << endl << endl << "Сумма чисел в очериди: " << sum << endl << endl;
		}
	}
}
void thirdlvl()
{
    queue <int> FirstNumbers, SecondNumbers;

    int* P1, * P2, * P3, * P4, arr[3], count = 0;
	cout << "Элементы первой очереди:";
    for (int i = 1; i <= 10; i++)
    {
		if (i % 2 != 0)
		{
			SecondNumbers.push(i);
			cout << SecondNumbers.back() << " ";
		}
    }  
	cout << endl;
	cout << "Элементы второй очереди:";
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			FirstNumbers.push(i);
			cout << FirstNumbers.back() << " ";
		}
	}

    cout << endl << endl;

    //присваиваем адреса и выводим их;
    P1 = &FirstNumbers.front();
    P2 = &FirstNumbers.back();
    P3 = &SecondNumbers.front();
    P4 = &SecondNumbers.back();

    cout << endl << "Адреса первого и последнего элементов первой очереди: " << P1 << ", " << P2 << endl;
	cout << endl << "Адреса первого и последнего элементов второй очереди: " << P3 << ", " << P4 << endl;
	cout << endl;
}

int main()
{
	setlocale(0, "");
	srand(time(0));

	int a;
	while (true)
	{
		cout << "Numbers of levels are 1 2 3 (0 to exit)\n";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1:
			cout << "Создать стек из вещественных чисел. Определить максимальный элементв стеке. Организовать просмотр данных стека." << endl << endl;
			firstlvl();
			break;
		case 2:
			cout << "Создать очередь вещественных значений, для реализации используя односвязные списки. Реализовать операции добавления(enqueue) и удаление(dequeue) элемента из очереди. Добавьте в очередь числа 2.1,2.1, 5.3 и распечатайте содержимое очереди. Удалите 1 элемент изочереди, затем добавьте в очередь число 4.9 и распечатайте очередь ещераз. Найдите сумму элементов очереди." << endl << endl;
			secondlvl();
			break;
		case 3:
			cout << "Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из исходного набора с нечетными номерами (1, 3,…, 9), а вторая -с четными (2, 4,…, 10); в каждой очереди должен совпадать с порядком чисел в исходном наборе. Вывести указатели на начало и конец первой, а затем второй очереди." << endl << endl;
			thirdlvl();
			break;
		case 0:
			return(0);
			break;
		default:
			cout << "Incorrect number, try again" << endl;
			break;
		}
	}
}
