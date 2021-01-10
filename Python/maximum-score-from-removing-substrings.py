# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        def score(s, a, x):
            i = result = 0
            for j in xrange(len(s)):
                s[i] = s[j]
                i += 1
                if i >= 2 and s[i-2:i] == a:
                    i -= 2
                    result += x
            s[:] = s[:i]
            return result
                
        s, a, b = list(s), list("ab"), list("ba")
        if x < y:
            x, y = y, x
            a, b = b, a
        return score(s, a, x) + score(s, b, y)
