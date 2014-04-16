class Solution:
	# @param s, a string
	# @return a string
	def reverseWords(self, s):
		a = s.split()
		a.reverse()
		return ' '.join(a)

x = Solution()
print x.reverseWords('  the   sky  is blue ')