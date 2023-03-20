# Time:  O(n)
# Space: O(n)

# freq table, contructive algorithms
class Solution(object):
    def maximizeGreatness(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return len(nums)-max(collections.Counter(nums).itervalues())
  

# Time:  O(nlogn)
# Space: O(1)
# sort, greedy, two pointers
class Solution2(object):
    def maximizeGreatness(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        left = 0
        for right in xrange(len(nums)):
            if nums[right] > nums[left]:
                left += 1
        return left
