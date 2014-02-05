N = input()
mat = [list(raw_input()) for i in xrange(N)]
for i in xrange(N):
	for j in xrange(N):
		if 0 <= i-1 and 0 <= j-1 and i+1 < N and j+1 < N:
			if mat[i][j] == '.':
				continue
			if mat[i-1][j] == '.':
				continue
			if mat[i+1][j] == '.':
				continue
			if mat[i][j-1] == '.':
				continue
			if mat[i][j+1] == '.':
				continue
			mat[i][j] = '.'
			mat[i-1][j] = '.'
			mat[i+1][j] = '.'
			mat[i][j-1] = '.'
			mat[i][j+1] = '.'
tmp = []
for x in mat:
	tmp += x
print "NO" if '#' in tmp else "YES"
