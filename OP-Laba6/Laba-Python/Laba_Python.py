import math

# Визначення точок перетину
def xt(d, e, eps):
	xy = 5
	x1 = y(d, 5)
	x2 = y(e, 5)
	while x1 < x2: # Зменшуємо відрізок вдвічі
		xy = xy / 2
		x1 = y(d, xy)
		x2 = y(e, xy)
	a = xy
	c = xy
	b = 0
	xn = 0
	while math.fabs(a-xn) > eps:
		xn = a
		while y(d, a) > y(e, a): # Зменшуємо відрізок і додаємо попереднє значення
			if (a == xy):
				a = 0
			b += xy / 2
			xy = xy / 2
			a = c + b
		while y(d, a) < y(e, a): # Зменшуємо відрізок і віднімаємо його від попереднього значення
			a = a - xy / 2
			xy = xy / 2
		b = 0
		c = a
	return a

# Визначаємо Solution
def Solution(eps):
	x11 = xt(1,2,eps) #Точка перетину cos i log
	x22 = xt(3,2,eps) #Точка перетину exp i log
	x33 = xt(1,3,eps) #Точка перетину cos i exp
	S = integral(x11, x33, 1,eps) + integral(x22, x11, 2,eps) - integral(x22, x33, 3,eps)
	return S

def y(x2, x1):
	x = 0
	if x2 == 1: 
		x = 2 / x1 * math.cos(x1 / 2)
	elif x2 == 2:
		x = math.log(1 + x1 * x1)
	elif x2 == 3:
		x = math.pow(math.e, -x1 * x1)
	return x

def integral(a, b, c,eps):
	I = eps + 1
	I1 = 0 # I-попереднє обчислене значення інтеграла, I1-нове, з більшим N.
	N = 2
	while (N <= 4) or (math.fabs(I1 - I) > eps):
		sum2 = 0
		sum4 = 0
		sum = 0
		h = (b - a) / (2 * N); # Крок інтегрування.
		i = 1
		while i <= 2 * N - 1:
			sum4 += y(c,(a + h * i)) # Значення з непарними індексами, які потрібно помножити на 4.
			sum2 += y(c,(a + h * (i + 1))) # Значення з парними індексами, які потрібно помножити на 2.
			i += 2
		sum = y(c,a) + 4 * sum4 + 2 * sum2 - y(c,b); # Віднімаємо значення y(b), так як раніше його додали двічі. 
		I = I1;
		I1 = (h / 3) * sum;
		N *= 2
	return I1

epsylon = float(input('Введіть точність > 0: '))
Sq = Solution(epsylon)
print('\nПлоща фігури = ', Sq, end='\n\n')