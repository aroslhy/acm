N, M = map(int, raw_input().split())
d = set(map(int, raw_input().split()) if M else [])
print "NO" if 1 in d or N in d or [x for x in d if x-1 in d and x+1 in d] else "YES"
