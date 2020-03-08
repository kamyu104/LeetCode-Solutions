# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numTimesAllBlue(self, light):
        """
        :type light: List[int]
        :rtype: int
        """
        result, right = 0, 0
        for i, num in enumerate(light, 1):
            right = max(right, num)
            result += (right == i)
        return result
