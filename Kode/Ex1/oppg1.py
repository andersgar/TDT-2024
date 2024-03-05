def isFibonaccinumber(n):
    a = 0
    b = 1
    while b < a:
        temp = b
        b += a
        a = temp
    return b == n

print(isFibonaccinumber(1))