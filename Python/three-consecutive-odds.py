# Time:  O(n)
# Space: O(1)

class Solution(object):
    def threeConsecutiveOdds(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        count = 0
        for x in arr:
            count = count+1 if x%2 else 0
            if count == 3:
                return True
        return False
