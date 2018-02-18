# Time:  O(nlogr)
# Space: O(1)

# A sorted list A contains 1, plus some number of primes.
# Then, for every p < q in the list, we consider the fraction p/q.
#
# What is the K-th smallest fraction considered?
# Return your answer as an array of ints, where answer[0] = p and answer[1] = q.
#
# Examples:
# Input: A = [1, 2, 3, 5], K = 3
# Output: [2, 5]
# Explanation:
# The fractions to be considered in sorted order are:
# 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
# The third fraction is 2/5.
#
# Input: A = [1, 7], K = 1
# Output: [1, 7]
#
# Note:
# - A will have length between 2 and 2000.
# - Each A[i] will be between 1 and 30000.
# - K will be between 1 and A.length * (A.length + 1) / 2.

class Solution(object):
    def kthSmallestPrimeFraction(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        def check(mid, A, K, result):
            tmp = [0]*2
            count = 0
            j = 0
            for i in xrange(len(A)):
                while j < len(A):
                    if i < j and A[i] < A[j]*mid:
                        if tmp[0] == 0 or \
                           tmp[0]*A[j] < tmp[1]*A[i]:
                            tmp[0] = A[i]
                            tmp[1] = A[j]
                        break
                    j += 1
                count += len(A)-j
            if count == K:
                result[:] = tmp
            return count >= K

        result = []
        left, right = 0.0, 1.0
        while right-left > 1e-8:
            mid = left + (right-left) / 2.0
            if check(mid, A, K, result):
                right = mid
            else:
                left = mid
            if result:
                break
        return result
