# c에서는 strcmp를 이용해서 비교하면된다. 선택 삽입 힙 퀵 머지 정렬중에 하나 구현
# -*- coding: utf-8 -*-
tmp = {"A":1,"B":2,"C":3,"D":4,"E":5,"F":6,"G":7,"H":8,"I":9,"J":10,"K":11,"L":12,"M":13,"N":14,"O":15,"P":16,"Q":17,"R":18,"S":19,"T":20,"U":21,"V":22,"W":23,"X":24,"Y":25,"Z":26}
result_sum = 0
result_twice = 1
total = 0
f = open("names.txt").read().split(",")

count = len(f)
for i in range(count):
    f[i] = f[i].strip('"')
f.sort()

#테스트
for x in range(count): 
    for i in range(len(f[x])):
        try:
            result_sum += tmp[f[x][i:i+1]]
        except KeyError:
            pass
    result_twice = result_sum*(x+1)
    total += result_twice
    print x, f[x], result_sum, result_twice,total
    result_sum = 0
    result_twice = 1

 

