# Time:  O(t * m * n), t is target
# Space: O(t)

class Solution(object):
    def minimizeTheDifference(self, mat, target):
        """
        :type mat: List[List[int]]
        :type target: int
        :rtype: int
        """
        chosen_min = sum(min(row) for row in mat)
        if chosen_min >= target:
            return chosen_min-target
        dp = {0}
        for row in mat:
            dp = {total+x for total in dp for x in row if (total+x)-target < target-chosen_min}
        return min(abs(target-total) for total in dp)
