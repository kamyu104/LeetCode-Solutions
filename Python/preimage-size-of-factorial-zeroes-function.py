# Time:  O((logn)^2)
# Space: O(1)

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

