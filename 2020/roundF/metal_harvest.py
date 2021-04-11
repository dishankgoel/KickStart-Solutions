from math import ceil
t = int(input())

for _ in range(t):
    n, k = [int(i) for i in input().split()]
    a = []
    for i in range(n):
        s, e = [int(i) for i in input().split()]
        a.append((s,e))
    a.sort(key = lambda x: x[0])
    curr_end = 0
    ans = 0
    for i in range(n):
        s,e = a[i][0], a[i][1]
        start = 0
        if(curr_end >= e):
            continue
        if(curr_end < s):
            start = s
        else:
            start = curr_end
        to_put =  ceil((e - start)/k)
        ans += to_put
        curr_end = start + to_put*k
    print("Case #{}: {}".format(_ + 1, ans))