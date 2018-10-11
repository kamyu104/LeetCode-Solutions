# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        def count(A, bound):
            result, curr = 0, 0
            for i in A :
                curr = curr + 1 if i <= bound else 0
                result += curr
            return result

        return count(A, R) - count(A, L-1)

