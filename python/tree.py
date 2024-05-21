def tree(label, branches=[]):
	for branch in branches:
		assert is_tree(branch)
	return [label] + list(branches)

def label(tree):
	return tree[0]

def branches(tree):
	return tree[1:]

def is_tree(tree):
	if type(tree) != list or len(tree) < 1:
		return False
	for branch in branches(tree):
		if not is_tree(branch):
			return False
	return True

def is_leaf(tree):
<<<<<<< HEAD
<<<<<<< HEAD
	if len(tree) == 1:
		return True
	else:
		return False
=======
	return not branches(tree)
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
=======
	return not branches(tree)
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef

def fib_tree(n):
	if n <= 1:
		return tree(n)
	else:
		left, right = fib_tree(n-2), fib_tree(n-1)
<<<<<<< HEAD
<<<<<<< HEAD
		return tree(label(left)+label(right), [left, right])

def count_leaves(t):
	num = 0
	if is_leaf(t):
		return 1
#	for branch in branches(t):
#		num += count_leaves(branch)
#	return num
	else:
		branch_counts = [count_leaves(b) for b in branches(t)]
		return sum(branch_counts)
=======
=======
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
		return tree(label(left) + label(right), [left, right])

def count_leaves(t):
	if is_leaf(t):
		return 1
	else:
		return sum([count_leaves(b) for b in branches(t)])
<<<<<<< HEAD
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
=======
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef

def leaves(tree):
	if is_leaf(tree):
		return [label(tree)]
	else:
<<<<<<< HEAD
<<<<<<< HEAD
		return sum([leaves(branch) for branch in branches(tree)], [])
=======
		return sum(leaves(b) for b in branches(tree))
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
=======
		return sum(leaves(b) for b in branches(tree))
>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef

def increment_leaves(t):
	if is_leaf(t):
		return tree(label(t) + 1)
	else:
<<<<<<< HEAD
<<<<<<< HEAD
		bs = [increment_leaves(b) for b in branches(t)]
		return tree(label(t), bs)

def increment(t):
	return tree(label(t) + 1, [increment(b) for b in branches(t)])

def print_tree(t, indent=0):
	print(' ' * indent + str(label(t)))
	for b in branches(t):
		print_tree(b, indent+1)

def my_print_sums(tree):
	if is_leaf(tree):
		return 1
	else:
		branch_counts = [my_print_sums(b) for b in branches(tree)]
		return sum(branch_counts) + 1

def print_sums(t, so_far):
	so_far = so_far + label(t)
	if is_leaf(t):
		print(so_far)
	else:
		for b in branches(t):
			print_sums(b, so_far)

#def count_paths(t, totals):
#	if is_leaf(t):
#		if label(t) == totals:
#			return 1
#		else:
#			return 0
#	else:
#		if label(t) == totals:
#			flag = 1
#		else:
#			flag = 0
#		return flag + sum([count_paths(b, totals-label(t)) for b in branches(t)])

def count_paths(t, totals):
	if label(t) == totals:
		found = 1 
	else:
		found = 0
	return found + sum([count_paths(b, totals - label(t)) for b in branches(t)])

def has_path(t, p):
	if p == [label(t)]:
		return True
	elif label(t) != label(p):
		return False 
	else:
	 return any([has_path(b, p[1:]) for b in branches(t)]) 

def find_path(t, x):
	if label(t) == x:
		return [label(t)]
	for b in branches(t):
		path = find_path(b, x)
	return None



t2 = tree(5, [tree(6), tree(7)]) 
t1 = tree(3, [tree(4), t2])
print(has_path(t2, [5, 6]))
=======
		bs = 

>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
=======
		bs = 

>>>>>>> a6e1d5dabdbd8c2b4d49945224761cd3309122ef
