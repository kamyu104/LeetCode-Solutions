# Time:  O(nlogn)
# Space: O(1)

# math
class Solution(object):
    def minimumRemoval(self, beans):
        """
        :type beans: List[int]
        :rtype: int
        """
        beans.sort()
        return sum(beans) - max(x*(len(beans)-i)for i, x in enumerate(beans))
