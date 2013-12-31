[N, K] = map(int, raw_input().split())
a = [x-1 for x in map(int, raw_input().split())]
print sum(min(sum(a[i::K]), N/K-sum(a[i::K])) for i in range(K))

