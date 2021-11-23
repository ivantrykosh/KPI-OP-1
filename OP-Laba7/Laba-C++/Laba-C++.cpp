#include <iostream>   // Для вводу-виводу
#include <stdlib.h>   // Для випадкового числа
#include <cmath>      // Для абсолютного значення числа
#include <iomanip>    // Для форматованого виводу

using namespace std;

void Input_array(int*, int);          // Заповнюємо масив
void Output_array(int*, int);         // Виводимо масив
void Solution(int*, int*, int*, int); // Перетворюємо масив
void Browse(int*, int*, int*, int);   // Виводимо кінцевий масив
void Sum(int*, int*, int*, int);      // Сума елементів половин масиву

int main()
{
	const int n = 10;   // Розмір масиву
	int A[n];
	int eps;     // Модуль кінцевої різниці між сумами елементів половин масиву
	int	eps1;    // Модуль початкової різниці між сумами елементів половин масиву
	Input_array(A, n);  // Ініціалізуємо масив
	Output_array(A, n); // Виводимо початковий масив
	Solution(A, &eps1, &eps, n);     // Оброблюємо масив
	Browse(A, &eps1, &eps, n);   // Виводимо оброблений масив
}

void Input_array(int *p, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(p+i) = rand() % 21 - 10; // Випадкові числа від -10 до 10
	}
}

void Output_array(int* p, int n)
{
	cout << "Array:  ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << *(p + i) << "  "; // Виводимо елементи початкового масиву
	}
}

void Solution(int* p, int *g, int *s, int n)
{
	int sum1 = 0; // Сума елементів першої половини
	int	sum2 = 0; // Сума елементів другої половини
	int a;        // Елемент масиву, що міняється місцями

	Sum(p, &sum1, &sum2, n); // Обчислюємо суму елементів масиву
	*s = abs(sum1 - sum2);   // Модуль різниці сум елементів половин
	*g = *s;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			for (int k = n / 2; k < n; k++)
			{
				// Елемент масиву, що змінюється
				a = *(p + j); 

				// Міняємо елементи місцями
				*(p + j) = *(p + k);
				*(p + k) = a;

				Sum(p, &sum1, &sum2, n); // Обчислюємо суму елементів масиву

				/* Якщо кінцеве значення різниці менше за модуль різниці, то змінємо елементи назад
				   інакше різниці eps присвоюється нове значення різниці сум */
				if (*s < abs(sum1 - sum2))
				{
					*(p + k) = *(p + j);
					 *(p + j) = a;
				}
				else
				{
					*s = abs(sum1 - sum2);
				}

				// Обнуляємо значення сум елементів
				sum1 = 0; 
				sum2 = 0;
			}
		}
	}
}

void Sum(int *p, int *g, int *h, int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		*g += *(p + i);         // Обчислюємо суму елементів першої половини
		*h += *(p + n - i - 1); // Обчислюємо суму елементів другої половини
	}
}

void Browse(int *p, int* g, int* s, int n)
{
	cout << "\nEps1 = " << *g << " Eps2 = " << *s << endl;
	cout << "Answer: ";
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << *(p + i) << "  "; // Виводимо масив
	}
}