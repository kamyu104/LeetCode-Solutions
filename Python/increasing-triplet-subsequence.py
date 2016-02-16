# Time:  O(n)
# Space: O(1)

# Given an unsorted array return whether an increasing 
# subsequence of length 3 exists or not in the array.

# Formally the function should:
# Return true if there exists i, j, k 
# such that arr[i] < arr[j] < arr[k] 
# given 0 <= i < j < k <= n-1 else return false.
# Your algorithm should run in O(n) time complexity and O(1) space complexity.

# Examples:
# Given [1, 2, 3, 4, 5],
# return true.

# Given [5, 4, 3, 2, 1],
# return false.

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        first_min, second_min = None, None
        for i in nums:
            if first_min is None or first_min >= i:
                first_min = i
            elif second_min is None or second_min >= i:
                second_min = i
            else:
                return True
        return False

# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)

        exist_smaller = set()
        min_num = 0
        for i in xrange(1, n):
            if (nums[i] <= nums[min_num]):
                min_num = i
            else:
                exist_smaller.add(i)

        max_num = n - 1
        for i in reversed(xrange(n-1)):
            if (nums[i] >= nums[max_num]):
                max_num = i
            else:
                if i in exist_smaller:
                    return True

        return False
