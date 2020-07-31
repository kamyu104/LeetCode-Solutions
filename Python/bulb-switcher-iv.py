# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minFlips(self, target):
        """
        :type target: str
        :rtype: int
        """
        result, curr = 0, '0'
        for c in target:
            if c == curr:
                continue
            curr = c
            result += 1
        return result
