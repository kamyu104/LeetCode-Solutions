# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result, prev = 1, 0
        for i in xrange(len(nums)):
            if nums[i]-nums[prev] <= k:
                continue
            prev = i
            result += 1
        return result
