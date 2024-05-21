def add_rational(x, y):
	nx, dy = number(x), denom(x)
	ny, dy = number(x), denom(y)
	return rational(nx * dy + ny * dx, dx * dy)

def mul_rational(x, y):
	return rational(number(x) * number(y), denom(x) * denom(y))

def rationals_are_eqal(x, y):
	return number(x) * denom(y) == number(y) * denom(x)

def print_rational(x):
	print(number(x), "/", denom(x))

def rational(n, d):
	def select(name):
		if name == 'n':
			return n
		elif name == 'd':
			return d
	return select

def number(x):
	return x('n')

def denom(x):
	return x('d') 
