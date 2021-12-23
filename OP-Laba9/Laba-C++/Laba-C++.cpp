#include <iostream>
#include <string>

using namespace std;

void Init(string*, char*); // Ввід рядка та символу
string Solution(string, char*, int*, int*); // Обробка рядка
void Browse(string*, int*, int*); // Вивід кінцевого рядка
int find(string, char, int); // Знаходження першого входження символу у рядок
string del(string, int, int, int); // Видалення слова
string delspace(string); // Видалення пробілів на початку рядка

int main()
{
    string str; // Оголошуємо рядок
    char m;     // Символ, який ввів користувач
    int s = 0;  // Кількість вилучень
    int k = 2; // Для виводу результату

    Init(&str, &m);
    str = Solution(str, &m, &s, &k);
    Browse(&str, &s, &k);

}

void Init(string* str, char* m)
{
    cout << "Input a line:\n";
    getline(cin, *str);        // Вводимо рядок
    cout << "Input a symbol: ";
    cin >> *m;                 // Вводимо символ
}

int find(string str, char m, int length)
{
    int pos = -1; //Позиція елемента
    bool flag = true; //Для знаходження першого входження елемента
    for (int i = 0; i < length; i++)
    {
        if ((str[i] == m) && flag) // Знаходимо індекс заданого елемента
        {
            pos = i;
            flag = false;
        }
    }
    return pos;
}

string del(string str, int q, int k, int len)
{
    string l = "";
    for (int i = 0; i < len; i++)
    {
        if (i < q) // Якщо індекс менший за позицію першого символу слова, то
        {
            l += str[i];
        }
        else if (i >= (k + q)) //Якщо індекс більший за позицію останнього символу слова, то
        {
            l += str[i];
        }
    }
    return l;
}

string Solution(string str, char* m, int* s, int* k)
{
    int len, len1 = 0;    // Оголошуємо змінну для довжини рядка і слова
    int n = -1;   // Позиція цього символу
    int b = n;   // Попередня позиція символу
    char n1;     // Поточний символ
    bool flag = true; // Для визначення, чи потрібно видаляти слово
    bool flag1 = true; // Для виходу з циклу

    len = str.length(); // Визначаємо довжину рядка
    n = find(str, *m, len); // Знаходимо позицію елемента, який ввів користувач
    if (len == 0) // Перевіряємо, чи рядок пустий
    {
        *k = 0;
    }
    else if (n == -1) // Перевіряємо, чи містить рядок задані символи
    {
        *k = 1;
    }
    else
    {
        if (n == 0) // Якщо потрібно, видаляємо перше слово у рядку
        {
            for (int i = n; i < len - 1; i++)
            {
                n1 = str[i]; // Поточний елемент
                if (((str[i + 1] == ' ') || (str[i + 1] == '\0')) && (n1 == *m) && flag) // Якщо після нього стоїть " ", то видаляємо слово
                {                                                               // то видаляємо слово     
                    len1 = i - n + 1; // Довжина слова
                    flag = false;
                }
            }
            if (len1 != 0)
            {
                str = del(str, n, len1, len); // Видаляємо слово
                *s += 1;
                len1 = 0;
            }
        }
        flag = true;
        n = -1;
        cout << str << endl;
        len = str.length();
        n = find(str, *m, len); // Знаходимо позицію елемента, який ввів користувач
        while ((n != -1) && flag1)
        {
            b = n;
            len1 = 0;
            if (str[n - 1] == ' ') // Якщо перед символом стоїть ' ', то перевіряємо, чи потрібно видаляти слово
            {
                for (int j = n - 1; j < len; j++) 
                {
                    n1 = str[j]; // Поточний елемент
                    if (((str[j + 1] == ' ') || (str[j + 1] == '\0')) && (n1 == *m) && flag) // Якщо після нього стоїть " ", або 0-ий символ,
                    {                                                         // то видаляємо слово
                        for (int k = n; k <= j; k++)
                        {
                            if (str[k] == ' ') // Якщо у виразі є ' ', то пропускаємо його
                            {
                                flag = false;
                            }
                        }
                        if (flag)
                        {
                            len1 = j - n + 1; // Довжина слова
                            flag = false;
                        }
                    }
                }
            }
            if (len1 != 0)
            {
                str = del(str, n, len1, len); // Видаляємо слово
                *s += 1;
            }
            cout << str << endl;
            n = -1;
            len = str.length();
            n = find(str, *m, len); // Знаходимо позицію елемента, який ввів користувач
            if (n == b)
            {
                n = find(str, *m, len); // Знаходимо позицію з n+1
                b = n;
                len = str.length(); // Визначаємо довжину рядка
                if ((n+1) == len)
                {
                    flag1 = false;
                    if (str[n - 1] == ' ')
                    {
                        str = del(str, n, len1, len);
                    }
                }
            }
            flag = true;
        }
        str = delspace(str);
    }
    return str;
}

string delspace(string str)
{
    string h = "";
    bool flag = true;
    int index = 0;
    for (int i = 0; i < str.length(); i++) // Знаходимо перший символ, який не є ' '
    {
        if ((str[i] != ' ') && flag)
        {
            index = i;
            flag = false;
        }
    }
    for (int i = index; i < str.length(); i++) // Видаляємо пробіли на початку рядка
    {
        h += str[i];
    }
    return h;
}

void Browse(string* str, int* s, int* k)
{
    if (*k == 0)
    {
        cout << "The string is empty!";
    }
    else if (*k == 1)
    {
        cout << "This element is not in the string!";
    }
    else
    {
        cout << "Answer:\n" << *str << endl;
        cout << "N = " << *s;
    }
}