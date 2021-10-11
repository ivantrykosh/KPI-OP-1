// Задані натуральні числа m та n. Обчислити суму m останніх цифр числа n.
#include <iostream>

using namespace std;

int main()
{   
    // Оголошуємо змінні
    unsigned long m, n, S;

    // Вводимо дані
    cout << "Input n: ";
    cin >> n;
    cout << "Input m: ";
    cin >> m;
    S = 0;

    // Обчислюємо суму
    for (int i = 0; i < m; i++) {
        S += n % 10;
        n = n / 10;
    }
    cout << "Answer: " << S;
}
