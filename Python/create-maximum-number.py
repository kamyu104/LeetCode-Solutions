# Time:  O(k * (m + n + k)) ~ O(k * (m + n + k^2))
# Space: O(m + n + k^2)
#
# Given two arrays of length m and n with digits 0-9 representing two numbers.
# Create the maximum number of length k <= m + n from digits of the two.
# The relative order of the digits from the same array must be preserved.
# Return an array of the k digits. You should try to optimize your time
# and space complexity.
#
# Example 1:
# nums1 = [3, 4, 6, 5]
# nums2 = [9, 1, 2, 5, 8, 3]
# k = 5
# return [9, 8, 6, 5, 3]
#
# Example 2:
# nums1 = [6, 7]
# nums2 = [6, 0, 4]
# k = 5
# return [6, 7, 6, 0, 4]
#
# Example 3:
# nums1 = [3, 9]
# nums2 = [8, 9]
# k = 3
# return [9, 8, 9]
#

# DP + Greedy solution. (280ms)
class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def get_max_digits(nums, start, end, max_digits):
            max_digits[end] = max_digit(nums, end)
            for i in reversed(xrange(start, end)):
                max_digits[i] = delete_digit(max_digits[i + 1])

        def max_digit(nums, k):
            drop = len(nums) - k
            res = []
            for num in nums:
                while drop and res and res[-1] < num:
                    res.pop()
                    drop -= 1
                res.append(num)
            return res[:k]

        def delete_digit(nums):
            res = list(nums)
            for i in xrange(len(res)):
                if i == len(res) - 1 or res[i] < res[i + 1]:
                    res = res[:i] + res[i+1:]
                    break
            return res
    
        def merge(a, b):
            return [max(a, b).pop(0) for _ in xrange(len(a)+len(b))]

        m, n = len(nums1), len(nums2)

        max_digits1, max_digits2 = [[] for _ in xrange(k + 1)], [[] for _ in xrange(k + 1)]
        get_max_digits(nums1, max(0, k - n), min(k, m), max_digits1)
        get_max_digits(nums2, max(0, k - m), min(k, n), max_digits2)

        return max(merge(max_digits1[i], max_digits2[k-i])
                   for i in xrange(max(0, k - n), min(k, m) + 1))
