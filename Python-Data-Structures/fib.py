def fib1_topdown(n):
    if n == 1 or n == 0:
        return 1
    return fib1_topdown(n-1) + fib1_topdown(n-2)

def fib2_bottomup(n):
    if n == 1 or n == 0:
        return 1
    prev2 = 1
    prev1 = 1
    res = prev1 + prev2
    for i in range(2, n+1):
        res = prev1 + prev2
        prev2 = prev1
        prev1 = res
    return res



for i in range(20):
    print(fib2_bottomup(i) == fib1_topdown(i))