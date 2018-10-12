# Time:  O(n)
# Space: O(1)

class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        modified, prev = False, nums[0]
        for i in xrange(1, len(nums)):
            if prev > nums[i]:
                if modified:
                    return False
                if i-2 < 0 or nums[i-2] <= nums[i]:
                    prev = nums[i]    # nums[i-1] = nums[i], prev = nums[i]
#               else:
#                   prev = nums[i-1]  # nums[i] = nums[i-1], prev = nums[i]
                modified = True
            else:
                prev = nums[i]
        return True


