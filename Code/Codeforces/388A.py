N = input()
a = map(int, raw_input().split())
a.sort()
p = [1]
for x in a[1:]:
	mini = min(p)
	if x >= mini:
		p[p.index(mini)] += 1
	else:
		p.append(1)
print len(p)
