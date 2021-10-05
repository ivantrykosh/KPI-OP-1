import decimal
import math
# З точністю до 10^-6 обчислити значення функції ln((1+x)/x) за заданою формулою

# Вводимо значення х та ініціалізуємо деякі змінні
x = float(input('Input x: '))
n = 1
S = 1.0
a = math.pow(-1,n+1) * math.pow(x,n-1) / n
s = math.pow(-1,n+2) * math.pow(x,n) / (n+1)

# Обчислюємо значення функції
while (abs(s-a) > 0.000001) :
    a = math.pow(-1,n+1) * math.pow(x,n-1) / n
    n += 1
    s = math.pow(-1,n+1) * math.pow(x,n-1) / n
    S += s

# Виводимо результат
print('Answer: ', S)