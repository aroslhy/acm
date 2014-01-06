R, C = map(int, raw_input().split())
a = [raw_input() for i in xrange(R)]
print len([(i, j) for i in xrange(R) for j in xrange(C) if 'S' not in a[i] or 'S' not in map(list, zip(*a))[j]])
