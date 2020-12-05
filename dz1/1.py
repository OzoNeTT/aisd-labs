x = int(input())
y = int(input()) 

def quickPow(x,n):
	if (n == 0):
		return 1
	if (n == 1):
		return x

	if (n % 2 == 0): # chet
		numb = quickPow(x, n // 2)
		return numb ** 2
	else:    		 # ne chet
		return x * quickPow(x, n - 1)

	return numb


print(quickPow(x,y))