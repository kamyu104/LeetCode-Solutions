# Time:  O(n)
# Space: O(1)

# hash table
class Solution(object):
    def minimizedStringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(set(s))
