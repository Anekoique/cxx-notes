from operator import floordiv, mod

def divide_exact(n, d):
	"""
	>>> q
	201
	>>> r
	3
	"""
	return floordiv(n, d), mod(n, d)
a = 2013
b = 10
q, r = divide_exact(a, b)

print(q,r)
