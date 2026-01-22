# Time:  O(n)
# Space: O(1)

# math, sliding window
class Solution(object):
    def goodIndices(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        result = []
        curr, base = 0, 1
        for i in xrange(len(s)):
            if i == base*10:
                base *= 10
            curr = (curr%base)*10+(ord(s[i])-ord('0'))
            if curr == i:
                result.append(i)
        return result
