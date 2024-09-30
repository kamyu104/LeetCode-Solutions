# Time:  O(1)
# Space: O(1)

# bitmasks
class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        def popcount(x):
            return bin(x)[2:].count('1')

        return chr(ord('a')+popcount(k-1)%26)
