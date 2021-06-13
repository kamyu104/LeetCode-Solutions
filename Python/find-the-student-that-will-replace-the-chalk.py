# Time:  O(n)
# Space: O(1)

class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        k %= sum(chalk)
        for i, x in enumerate(chalk):
            if k < x:
                return i
            k -= x
        return -1
