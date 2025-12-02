# Time:  O(n)
# Space: O(n)

# counting sort, greedy
class Solution(object):
    def maxSum(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: List[int]
        :rtype: int
        """
        groups = [[] for _ in xrange(len(nums))]
        for i, x in enumerate(threshold):
            groups[x-1].append(i)
        sorted_idxs = []
        for i, g in enumerate(groups):
            sorted_idxs.extend(g)
        result = 0
        for step, i in enumerate(sorted_idxs, 1):
            if step < threshold[i]:
                break
            result += nums[i]
        return result
