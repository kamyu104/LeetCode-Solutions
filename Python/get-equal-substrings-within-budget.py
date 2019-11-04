# Time:  O(n)
# Space: O(1)

class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        """
        :type s: str
        :type t: str
        :type maxCost: int
        :rtype: int
        """
        left = 0
        for right in xrange(len(s)):
            maxCost -= abs(ord(s[right])-ord(t[right]))
            if maxCost < 0:
                maxCost += abs(ord(s[left])-ord(t[left]))
                left += 1
        return (right+1)-left
