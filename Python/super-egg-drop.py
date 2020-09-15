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
            # f(n, K): the max number of floors could be solved by n moves and K eggs
            # we want to do binary search to find min of n, s.t. f(n, K) >= N
            # => f(n, K) = f(n-1, K)+1 + // [1            , f(n-1, K)+1            ] is solvable by one move with one break
            #              f(n-1, K-1)   // [f(n-1, K)+1+1, f(n-1, K)+1+f(n-1, K-1)] is then solvable by remaining moves and eggs
            # => (1) f(n, K)   = f(n-1, K)  +1+f(n-1, K-1)
            #    (2) f(n, K-1) = f(n-1, K-1)+1+f(n-1, K-2)
            # let g(n, K) = f(n, K)-f(n, K-1), (1)-(2)
            # => g(n, K) = g(n-1, K)+g(n-1, K-1), it is binomial coefficient
            # => C(n, K) = g(n, K) = f(n, K)-f(n, K-1)
            # => f(n, K) = C(n, K)+f(n, K-1) = C(n, K) + C(n, K-1) + ... + C(n, 1) + f(n, 0) = sum(C(n, k) for k in [1, K])
            # => check sum(C(n, k) for k in [1, K]) >= N
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

