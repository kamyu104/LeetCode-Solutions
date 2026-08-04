# Time:  O(n)
# Space: O(1)

# prefix sum
class Solution(object):
    def countValidPrefixes(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = prefix = 0
        for x in s:
            prefix += 1 if x == '1' else -1
            if abs(prefix) <= 1:
                result += 1
        return result
