# -*- coding: utf-8 -*-
# c에서는 strcmp를 이용해서 비교하면된다. 선택 삽입 힙 퀵 머지 정렬중에 하나 구현

tmp = {"A":1,"B":2,"C":3,"D":4,"E":5,"F":6,"G":7,"H":8,"I":9,"J":10,"K":11,"L":12,"M":13,"N":14,"O":15,"P":16,"Q":17,"R":18,"S":19,"T":20,"U":21,"V":22,"W":23,"X":24,"Y":25,"Z":26}
f = open("words.txt").read().split(",")
value_buf = [0 for x in range(2048)]
count = len(f)
for i in range(count):
    f[i] = f[i].strip('"')
f.sort()

#테스트
index = 0 
max_value = 2048
result_sum = 0
word_count = 0
for x in range(max_value):
    index = x+index
    if index > max_value:
        break
    value_buf[index] = 1

for x in range(count):
    for i in range(len(f[x])):
        try:
            result_sum += tmp[f[x][i:i+1]]
        except KeyError:
            pass
    
    if value_buf[result_sum] == 1:
        word_count += 1
        print word_count,result_sum,f[x]
    result_sum = 0

print word_count
