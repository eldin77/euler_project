import math

count = 0
result_list = set()
for i in range(23,101):
    n = math.factorial(i)

    for j in range(i):
        r = math.factorial(j)
        c = math.factorial(i - j)
        result = n/(r*c)
        if(result >= 1000000):
            result_list.add(result)
            count += 1

print len(result_list),"result = ",count

