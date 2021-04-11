from math import ceil
t = int(input())
for _ in range(t):
    n, x = [int(i) for i in input().split()]
    l = input().split()
    a = [(ceil(int(l[i])/x), int(i)+1) for i in range(len(l))]
    a.sort(key = lambda x : x[0])
    print("Case #{}: ".format(_ + 1) + ' '.join([str(elem[1]) for elem in a]))
