#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std; // Простір імен

// Прототипи функцій обчислень
double integral(double, double, int, double); // Обчислення інтеграла
double x(int, int, double);                   // Обчислення точок перетину
double y(int, double);                // Обчислення функцій

// Прототипи функцій вводу, обчислень та виводу
double Init();         // Функція вводу
double Solution(double, double, double, double);     // Функція обчислень
void Browse(double);       // Функція виводу

int main()
{
	double x11, x22, x33, s, epsyl;  // Точки перетину, площа і точність
	epsyl = Init();
	x11 = x(1, 2, epsyl); // Точка перетину cos і log
	x22 = x(3, 2, epsyl); // Точка перетину exp і log  
	x33 = x(1, 3, epsyl); // Точка перетину cos і exp
	s = Solution(x11, x22, x33, epsyl);
	Browse(s);
}

// Визначаємо функцію для обчислення заданих функцій
double y(int x2, double x1)
{
	double x = 0;
	if (x2 == 1)
		x = 2 / x1 * cos(x1 / 2);
	else if (x2 == 2) 
		x = log(1 + x1 * x1);
	else if (x2 == 3) 
		x = pow(M_E, -x1 * x1);
	return x;
}

// Визначаємо функцію обчислення інтеграла
double integral(double a, double b, int c, double eps)
{
	double I = eps + 1, I1 = 0; // I-попереднє обчислене значення інтеграла, I1-нове, з більшим N.
	for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
	{
		double h;
		double sum2 = 0;
		double sum4 = 0;
		double sum = 0;

		h = (b - a) / (2 * N); // Крок інтегрування.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += y(c,(a + h * i)); // Значення з непарними індексами, які потрібно помножити на 4.
			sum2 += y(c,(a + h * (i + 1))); // Значення з парними індексами, які потрібно помножити на 2.
		}
		sum = y(c,a) + 4 * sum4 + 2 * sum2 - y(c,b); // Віднімаємо значення y(b), так як раніше його додали двічі. 
		I = I1;
		I1 = (h / 3) * sum;
	}
	return I1;
}

// Визначення точок перетину
double x(int d, int e, double eps)
{
	double x, a, b, c, xn;
	x = 5;
	while (y(d, x) < y(e, x)) // Зменшуємо відрізок вдвічі
	{
		x = x / 2;
	}
	a = 0;
	xn = 1;
	c = x;
	b = 0;

	while (fabs(a-xn) > eps) 
	{
		xn = a;
		while (y(d, a) > y(e, a)) // Зменшуємо відрізок і додаємо попереднє значення
		{
			b += x / 2;
			x = x / 2;
			a = b + c;
		}
		while (y(d, a) < y(e, a)) // Зменшуємо відрізок і віднімаємо його від попереднього значення
		{
			a -= x / 2;
			x = x / 2;
		}
		b = 0;
		c = a;
	}
	return a;
}

// Визначаємо Init
double Init()
{
	double epsylon;        // Точність
	cout << "Input epsylon > 0: ";
	cin >> epsylon;
	return epsylon;
}

// Визначаємо Solution
double Solution(double x111, double x222, double x333, double eps)
{
	double S;              // Площа фігури
	S = integral(x111, x333, 1, eps) + integral(x222, x111, 2, eps) - integral(x222, x333, 3, eps);
	return S;
}

// Визначаємо Browse
void Browse(double S)
{
	cout << "\nAnswer: " << S << endl;
}