N, M = map(int, raw_input().split())
c = 0; ans = 0
while True:
	c = (c+1)%M
	if N > 0:
		ans += 1
		N -= 1
	else:
		break
	if c == 0:
		N += 1
print ans
