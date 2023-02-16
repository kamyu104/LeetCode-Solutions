# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers
class Solution(object):
    def countFairPairs(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def count(x):
            cnt = 0
            left, right = 0, len(nums)-1
            while left < right:
                if nums[left]+nums[right] <= x:
                    cnt += right-left
                    left += 1
                else:
                    right -= 1
            return cnt
        
        nums.sort()
        return count(upper)-count(lower-1)
