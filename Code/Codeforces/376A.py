s = raw_input()
m = s.index('^')
sm = 0
s = s.replace('=', '0').replace('^', '0')
for i in range(len(s)):
	sm += (m-i)*int(s[i])
print "left" if sm > 0 else "balance" if sm == 0 else "right"

