a, b = map(int, raw_input().split())
print len([x for x in range(1, 7) if abs(x-a) < abs(x-b)]),
print len([x for x in range(1, 7) if abs(x-a) == abs(x-b)]),
print len([x for x in range(1, 7) if abs(x-a) > abs(x-b)])

