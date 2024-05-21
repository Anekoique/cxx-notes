num = 0
def hailstone(n):
    num += 1
    if n == 1:
        return 1
    elif n % 2 == 0:
        if(hailstone(n//2)):
            return 1
    else:
        if(hailstone(n*3+1)):
            return 1

