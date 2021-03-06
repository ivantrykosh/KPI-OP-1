# Робота світлофора для пішоходів запрограмована таким чином: на початку кожної години протягом трьох 
# хвилин горить зелений сигнал, потім протягом двох хвилин червоний, протягом трьох хвилин - знову 
# зелений і т. д. Дано дійсне число t, що означає час в хвилинах, що минув з початку чергового години.
# Визначити, сигнал якого кольору горить для пішоходів в цей момент.

# Вводимо час у хвилинах:
print('Input minute: ')
t = float(input())

# Присвоюємо початкові значення змінних:
b = 0
a = 0

while (b <= t):
    b += 5
    if (t == b):
        a = 1
    else:
        if (t == b - 1):
            a = 1

# Виводимо результат:
if (a == 1):
    print('Red')
else :
    print('Green')