# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        return max((26-(ord(x)-ord('a')))%26 for x in s)
