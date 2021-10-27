/* Дано натуральне число n(n < 27).Отримати всі трьохзначні 
   натуральні числа, сума цифр яких дорівнює n. */
#include <iostream>
using namespace std;

int main()
{   
    // Оголошуємо змінні
    unsigned short int n;

    // Вводимо n
    cout << "Input a natural n < 27: ";
    cin >> n;

    cout << "Answer: ";

    // За допомогою циклу перелічуємо всі трьохзначні числа
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                // Визначаємо, чи сума цифр трьохзначного числа дорівнює n
                if ((i + j + k) == n)
                {   
                    // Виводимо результат
                    cout << i << j << k << " ";
                }
            }
        }
    }
    return 0;
}