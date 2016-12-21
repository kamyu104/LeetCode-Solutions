# Time:  O(n)
# Space: O(1)

# You are given an array of positive and negative integers.
# If a number n at an index is positive, then move forward n steps.
# Conversely, if it's negative (-n), move backward n steps.
# Assume the first element of the array is forward next to the last element,
# and the last element is backward next to the first element.
# Determine if there is a loop in this array.
# A loop starts and ends at a particular index with more than 1 element along the loop.
# The loop must be "forward" or "backward'.
#
# Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.
#
# Example 2: Given the array [-1, 2], there is no loop.
#
# Note: The given array is guaranteed to contain no element "0".
#
# Can you do it in O(n) time complexity and O(1) space complexity?

class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def next_index(nums, i):
            return (i + nums[i]) % len(nums)
            
        for i in xrange(len(nums)):
            if nums[i] == 0:
                continue
            
            slow, fast = i, i
            while nums[next_index(nums, slow)] * nums[i] > 0 and \
                  nums[next_index(nums, fast)] * nums[i] > 0 and \
                  nums[next_index(nums, next_index(nums, fast))] * nums[i] > 0:
                slow = next_index(nums, slow)
                fast = next_index(nums, next_index(nums, fast))
                if slow == fast: 
                    if slow == next_index(nums, slow):
                        break
                    return True

            slow, val = i, nums[i]
            while nums[slow] * val > 0:
                tmp = next_index(nums, slow)
                nums[slow] = 0
                slow = tmp

        return False
