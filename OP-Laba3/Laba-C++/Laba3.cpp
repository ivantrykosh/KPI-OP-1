#include <iostream>
#include <cmath>

// З точністю до 10^-6 обчислити значення функції ln((1+x)/x) за заданою формулою

using namespace std;

int main()
{	
	// Оголошуємо змінні
	float S, x, a;
	unsigned int n;

	// Вводимо значення х та ініціалізуємо деякі змінні
	cout << "Input x: ";
	cin >> x;
	n = 1;
	S = 0;
	a = 0;

	// Обчислюємо вираз
	do 
	{
		a += pow(-1, n + 1) * pow(x, n - 1) / n;
		n++;
		S += pow(-1, n + 1) * pow(x, n - 1) / n;
	} while ((S-a) > 0.000001);

	// Виводимо результат
	cout << "Answer: " << S;
	return 0;
}
