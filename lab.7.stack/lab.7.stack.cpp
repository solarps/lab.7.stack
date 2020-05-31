#include <iostream>
#include <ctime>
#include <stack>

using namespace std;

struct Stack
{
	double max=0;
	double a;
	Stack* prevstack = nullptr;
	Stack* prevA = nullptr;
	void setInf() {
		a =rand() % 100 * 0.1;
		if (a > max)
		{
			max = a;
		}
	}
	void getInf() {
		cout << a << "  ";
	}
	void getMax() {
		cout << endl << "Максимальный элемент: " << max << endl;
	}
};

struct StackOfNumbers
{
	Stack* max;
	Stack* currentA = nullptr;
	Stack* prevA = nullptr;

	void add()
	{
		prevA = currentA;
		currentA = new Stack();
		currentA->prevA = prevA;
		currentA->setInf();
	}

	void show()
	{
		prevA = currentA;
		while (currentA)
		{
			currentA->getInf();
			currentA = currentA->prevA;
		}
		max->getMax();
		currentA = prevA;
		prevA = prevA->prevA;
	}

	void clear()
	{
		while (currentA)
		{
			prevA = currentA->prevA;
			delete currentA;
			currentA = prevA;
		}
		prevA = nullptr; //Возможно не стоит
	}
};



void firstlvl() 
{
	StackOfNumbers stack;
	for (size_t i = 0; i < 10; i++)
	{
		stack.add();
	}
	stack.show();
	stack.clear();
}

void secondlvl()
{

}
void thirdlvl()
{

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
			cout << "Добавить в Memo или в StringGrid некоторое количество символов русского алфавита и записать их в бинарный файл. Переписать бинарный файл так, чтобы все символы были записаны заглавными буквами. Распечатать символы до и после изменения данных в файле." << endl << endl;
			secondlvl();
			break;
		case 3:
			cout << "Создать бинарный файл, компонентами которого является структура,содержащая следующие поля:\n- фамилия и инициалы покупателя;\n- дата покупки;\n- общая стоимость приобретенного товара за первое полугодие;\n- общая стоимость приобретенного товара за второе полугодие;\n- начальный процент скидки на последующие приобретаемые товары;\nПереписать бинарный файл так, чтобы процентная скидка была бы увеличена на 7%, если покупатель заплатил за предыдущий товар в первоми во втором полугодиях не менее 10000 грн." << endl << endl;
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
