''' Дано натуральне число n (n < 27). Отримати всі трьохзначні 
    натуральні числа, сума цифр яких дорівнює n. '''

# Вводимо n
n = int(input("Введіть натуральне n < 27: "))

print("Відповідь: ", end = " ")

# Перелічуємо всі трьохзначні натуральні числа
for i in range(1, 10):
    for j in range(0, 10):
        for k in range(0, 10):

            # Перевіряємо, чи сума цифр числа дорівнює n
            if (i + j + k) == n:

                # Виводимо результат
                print(i, j, k, sep =  "", end = " ")
print("")