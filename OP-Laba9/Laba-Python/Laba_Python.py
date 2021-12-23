def Init():
    s1 = input("Input the string:\n") # Вводимо рядок
    m = input("Input the symbol: ")  # Вводимо символ
    return s1, m    # Повертаємо введені значення

def list(str, length):
    st = []
    pos = 0 # Індекс першого символу, який не є пробілом
    m = "" # Слово
    j = True # Для знаходження pos

    for i in range(length):
        if j and str[i] != " ":
            pos = i # Індекс першого символу, який не є пробілом
            j = False

    for i in range(length): # Створюємо список зі слів рядка
        if str[i] != " ":
            m += str[i] # Накопичуємо сиволи у слові
        elif i >= pos:
            st = st + [m] # Збільшуємо список
            m = ""
        if (i == length - 1) and (str[i] != " "):
            st = st + [m] # Збільшуємо список
    return st

def str1(l, length): # Перетворюємо список у рядок
    s = ""
    for i in range(length):
        s += l[i] + " " # Збільшуємо рядок
    return s

def find(str, m, length): # Знаходимо позицію заданого елемента
    pos = -1
    for i in range(length):
        if str[i] == m:
            pos = i
    return pos

def delete(l, i, length): # Видаляємо елемент зі списку (пропускаємо його)
    s = []
    for j in range(i):
        s = s + [l[j]]
    for j in range(i+1, length):
        s = s + [l[j]]
    return s

def Solution(str, m):
    k = 2    # Для виводу результату
    length = len(str)    # Довжина рядка
    n = 0    # Кількість вилучень
    pos = find(str, m, length) # Знаходимо позицію заданого елемента
    if length == 0:    # Якщо рядок пустий, то вовидимо відповідне повідомлення
        k = 0
    elif pos == -1: # Якщо рядок не містить заданого символу, то виводимо відповідне повідомлення
        k = 1
    else:
        l = list(str, length) # Розбиваємо рядок на список
        i = 0 # Індекс елемента списку
        while i < len(l):
            s = l[i]    # і-тий елемент списку
            if (s[0] == m) and (s[-1] == m): # Перевіряємо, чи заданий символ є в кінці чи на початку слова
                l = delete(l, i, len(l))    # Видаляємо елемент зі списку
                n += 1    # Збільшуємо кількість видалень
                i -= 1    # Зменшуємо індекс, бо у списку стало на 1 елемент менше
            i += 1    # Збільшуємо індекс
        str = str1(l, len(l))    # Перетворюємо список у рядок
    return str, n, k    # Повертаємо рядок, кількість вилучень та k

def Browse(s2, s, k): # Виводимо відповідний результат
    if k == 0:
        print("The string is empty!")
    elif k == 1:
        print("This element is not in the string!")
    else:
        print("Answer:\n", s2, sep = "")
        print("N =", s)

s1, m = Init() # Вводимо рядок та символ
s1, s, k = Solution(s1, m) # Видаляємо слова
Browse(s1, s, k) # Виводимо результат