// GeneratNumber.cpp :  Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы. //

#include <iostream>
#include <cstring>
#include <cstdlib>

#define ch long long  // Директивой определил макрос ch (последвоательность символов) и его длинну

using namespace std;

/* Вычисление (a * b) % с учётом того, что результат может переполниться */

ch multiplication(ch a, ch b, ch mod)
{
	ch x = 0, y = a % mod;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			x = (x + y) % mod;
		}
		y = (y * 2) % mod;
		b /= 2;
	}
	return x % mod;
}

/* Модульное возведение в степень */

ch module(ch base, ch exponent, ch mod)
{
	ch x = 1;
	ch y = base;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			x = (x * y) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

/* Тест Миллера-Рабина */

bool Test(ch p, int iteration)
{
	if (p < 2)
	{
		return false;
	}
	if (p != 2 && p % 2 == 0)
	{
		return false;
	}
	ch s = p - 1;
	while (s % 2 == 0)
	{
		s /= 2;
	}
	for (int i = 0; i < iteration; i++)
	{
		ch a = rand() % (p - 1) + 1, temp = s;
		ch mod = module(a, temp, p);
		while (temp != p - 1 && mod != 1 && mod != p - 1)
		{
			mod = multiplication(mod, mod, p);
			temp *= 2;
		}
		if (mod != p - 1 && temp % 2 == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int iteration = 5;
	ch num;
	cout << "Введите число для его проверки на простоту: ";
	cin >> num;
	if (Test(num, iteration))
	{
		cout << " Число " << num << " простое " << endl;
	}
	else
	{
		cout << " Число " << num << " не простое " << endl;
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
