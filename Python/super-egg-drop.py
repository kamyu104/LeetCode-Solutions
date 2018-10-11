# Time:  O(klogn)
# Space: O(1)

class Solution(object):
    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        def check(n, K, N):
            # Each combinatin of n moves with k broken eggs could represent a unique F.
            # Thus, the range size of F that all cominations can cover 
            # is the sum of C(n, k), k = 1..K
            total, c = 0, 1
            for k in xrange(1, K+1):
                c *= n-k+1
                c //= k
                total += c
                if total >= N:
                    return True
            return False

        left, right = 1, N
        while left <= right:
            mid = left + (right-left)//2
            if check(mid, K, N):
                right = mid-1
            else:
                left = mid+1
        return left

