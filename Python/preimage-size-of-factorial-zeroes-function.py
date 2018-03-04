# Time:  O((logn)^2)
# Space: O(1)

# Let f(x) be the number of zeroes at the end of x!.
# (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
#
# For example, f(3) = 0 because 3! = 6 has no zeroes at the end,
# while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end.
# Given K, find how many non-negative integers x have the property that f(x) = K.
#
# Example 1:
# Input: K = 0
# Output: 5
# Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
#
# Example 2:
# Input: K = 5
# Output: 0
# Explanation: There is no x such that x! ends in K = 5 zeroes.
# Note:
# - K will be an integer in the range [0, 10^9].

class Solution(object):
    def preimageSizeFZF(self, K):
        """
        :type K: int
        :rtype: int
        """
        def count_of_factorial_primes(n, p):
            cnt = 0
            while n > 0:
                cnt += n//p
                n //= p
            return cnt

        p = 5
        left, right = 0, p*K
        while left <= right:
            mid = left + (right-left)//2
            if count_of_factorial_primes(mid, p) >= K:
                right = mid-1
            else:
                left = mid+1
        return p if count_of_factorial_primes(left, p) == K else 0
