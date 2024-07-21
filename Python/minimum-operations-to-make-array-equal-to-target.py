# Time:  O(n)
# Space: O(1)

# greedy, lc1526
class Solution(object):
    def minimumOperations(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        for i in xrange(len(target)):
            target[i] -= nums[i]
        return sum(max((target[i] if i < len(target) else 0)-(target[i-1] if i-1 >= 0 else 0), 0) for i in xrange(len(target)+1))
