# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def isConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return max(nums)-min(nums)+1 == len(nums) == len(set(nums))


# Time:  O(nlogn)
# Space: O(1)
# sort
class Solution2(object):
    def isConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()
        return all(nums[i]+1 == nums[i+1] for i in xrange(len(nums)-1))
