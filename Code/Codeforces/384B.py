N, M, K = map(int, raw_input().split())
a = [map(int, raw_input().split()) for i in xrange(N)]
print M*(M-1)/2
for i in xrange(M):
	for j in xrange(M-i-1):
		if not K:
			print i+1, i+j+2
		else:
			print i+j+2, i+1
