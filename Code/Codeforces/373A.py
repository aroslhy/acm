K = input()
mat = "".join(raw_input() for i in xrange(4))
print ("YES", "NO")[max(mat.count(str(i)) for i in xrange(1, 10)) > K*2]

