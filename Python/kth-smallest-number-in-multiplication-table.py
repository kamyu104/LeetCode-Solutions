# Time:  O(m * log(m * n))
# Space: O(1)

# Nearly every one have used the Multiplication Table.
# But could you find out the k-th smallest number quickly from the multiplication table?
#
# Given the height m and the length n of a m * n Multiplication Table, and a positive integer k,
# you need to return the k-th smallest number in this table.
#
# Example 1:
# Input: m = 3, n = 3, k = 5
# Output: 
# Explanation: 
# The Multiplication Table:
# 1	2	3
# 2	4	6
# 3	6	9
#
# The 5-th smallest number is 3 (1, 2, 2, 3, 3).
# Example 2:
# Input: m = 2, n = 3, k = 6
# Output: 
# Explanation: 
# The Multiplication Table:
# 1	2	3
# 2	4	6
#
# The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
# Note:
# The m and n will be in the range [1, 30000].
# The k will be in the range [1, m * n]

class Solution(object):
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """
        def count(target, m, n):
            return sum(min(target//i, n) for i in xrange(1, m+1))

        left, right = 1, m*n;
        while left <= right:
            mid = left + (right-left)/2
            if count(mid, m, n) >= k:
                right = mid-1
            else:
                left = mid+1
        return left
