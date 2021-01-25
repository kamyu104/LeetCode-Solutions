# Time:  O(m * n) on average
# Space: O(m * n)

import random


class Solution(object):
    def kthLargestValue(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1
        
        
        vals = []
        for r in xrange(len(matrix)):
            curr = 0
            for c in xrange(len(matrix[0])):
                curr = curr^matrix[r][c]
                if r == 0:
                    matrix[r][c] = curr
                else:
                    matrix[r][c] = curr^matrix[r-1][c]
                vals.append(matrix[r][c])
        nth_element(vals, k-1, compare=lambda a, b: a > b)
        return vals[k-1]
