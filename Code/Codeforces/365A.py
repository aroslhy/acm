[N, K] = map(int, raw_input().split())
ans = 0
for i in xrange(N):
	a = raw_input()
	ans += all(j in a for j in "0123456789"[:K+1])
print ans

