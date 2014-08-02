N = input()
mat = [['*' for i in xrange(N)] for j in xrange(N)]
mid = N/2
for i in xrange(N):
	x = i if i < mid else N-i-1
	for j in xrange(x+1):
		mat[i][mid+j] = 'D'
		mat[i][mid-j] = 'D'
for i in xrange(N):
	print ''.join(mat[i])
