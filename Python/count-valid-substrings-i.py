# Time:  O(n)
# Space: O(1)

# combinatorics
class Solution(object):
    def countValidSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = l = 0
        for i in xrange(len(s)):
            l += 1
            if not (i-2 >= 0 and s[i-2:i+1] == "abc"):
                continue
            result += (l-1)*l//2-1
            l = 2
        result += l*(l+1)//2
        return result
