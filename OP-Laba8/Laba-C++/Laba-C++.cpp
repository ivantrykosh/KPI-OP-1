#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void Input_array(int* , int);   // Ініціалізуємо масив
void Output_array(int* , int);  // Виводимо початковий масив
void Solution(int*, int*, int&, int); // Міняємо елементи місцями і знаходимо значення на перетині діагоналей
void Browse(int*, int&, int);   // Виводимо кінцевий масив

int main()
{
	const int n = 5; // Розмір масиву (непарне число)
	int A[n][n];     // Початковий масив А
	int* a = &A[0][0]; // Посилання на перший елемент масиву А
	int B[n][n];       // Кінцевий масив В
	int* b = &B[0][0]; // Посилання на перший елемент масиву В
	int element = 0;   // Значення на перетині діагоналей

	Input_array(a, n);  // Ініціалізуємо масив А
	Output_array(a, n); // Виводимо масив А
	Solution(a, b, element, n); // Ініціалізуємо та оброблюємо масив В
	Browse(b, element, n);    // Виводимо масив В і значення на перетині діагоналей

	return 0;
}

void Input_array(int* p, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(p + n * i + j) = rand() % 21 - 10; // Присвоюємо елементам масиву А випадкові числа
		}
	}
}

void Output_array(int* p, int n)
{
	cout << "Array A:";
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << *(p + n * i + j); // Виводимо масив А
		}
	}
}

void Solution(int* p, int* g, int& m, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == j) && ((i + j) == (n - 1)))
			{
				m = *(p + n * i + j);   // Знаходимо значення на перетині головних діагоналей
			}

			// Якщо елемент лежить у верхній чверті, то присвоїти його відповідному елементу з нижньої чверті
			if ((i <= j) && ((i + j) <= (n - 1)))
			{
				*(g + n * i + j) = *(p + n * (n - i - 1) + j);
			}
			// Якщо елемент лежить у нижній чверті, то присвоїти його відповідному елементу з верхньої чверті
			else if ((i >= j) && ((i + j) >= (n - 1)))
			{
				*(g + n * i + j) = *(p + n * (n - i - 1) + j);
			}
			// Інакше присвоїти елементу масиву В відповідний елемент з масиву А
			else
			{
				*(g + n * i + j) = *(p + n * i + j);
			}
		}
	}
}

void Browse(int* p, int& m, int n)
{
	cout << "\n\nElement: " << m; // Виводимо значення на перетині діагоналей
	cout << "\n\nArray B:";
	for (int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << setw(5) << *(p + n * i + j); // Виводимо масив В
		}
	}
}