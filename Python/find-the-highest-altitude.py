# Time:  O(n)
# Space: O(1)

class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        result = curr = 0
        for g in gain:
            curr += g
            result = max(result, curr)
        return result
