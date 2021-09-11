#include <stdio.h>
#include "math.h"

/* Трикутник задано довжинами сторін. Знайти довжини бісектрис,
   радіуси вписаного  та описаного кіл. */

int main(void)
{	
	unsigned int a, b, c;
	double lc, la, lb, p, r, R, S;

	// Вводимо значення сторін:
	printf("Input a: ");
	scanf_s(" %u", &a);
	printf("Input b: ");
	scanf_s(" %u", &b);
	printf("Input c: ");
	scanf_s(" %u", &c);

	// Проводимо обчислення:
	lc = sqrt(a * b * (a + b + c) * (a + b - c)) / (a + b);
	la = sqrt(c * b * (a + b + c) * (c + b - a)) / (c + b);
	lb = sqrt(a * c * (a + b + c) * (a + c - b)) / (a + c);
	p = (a + b + c) / 2;
	r = sqrt((p - a) * (p - b) * (p - c) / p);
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	R = (a * b * c) / (4 * S);

	// Виводимо відповідь:
	printf("bisector_a = %f; bisector_b = %f; bisector_c = %f;", la, lb, lc);
	printf("\nradius of the inscribed circle = %f; \nradius of the circumscribed circle = %f.", r, R);
	return 0;
}