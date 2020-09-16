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
            # let f(n, K) be the max number of floors could be solved by n moves and K eggs,
            # we want to do binary search to find min of n, s.t. f(n, K) >= N,
            # if we use one move to drop egg with X floors
            # 1. if it breaks, we can search new X in the range [X+1, X+f(n-1, K-1)]
            # 2. if it doesn't break, we can search new X in the range [X-f(n-1, K), X-1]
            # => f(n, K) = (X+f(n-1, K-1))-(X-f(n-1, K))+1 = f(n-1, K-1)+f(n-1, K)+1
            # => (1) f(n, K)   = f(n-1, K)  +1+f(n-1, K-1)
            #    (2) f(n, K-1) = f(n-1, K-1)+1+f(n-1, K-2)
            # let g(n, K) = f(n, K)-f(n, K-1), and we subtract (1) by (2)
            # => g(n, K) = g(n-1, K)+g(n-1, K-1), obviously, it is binomial coefficient
            # => C(n, K) = g(n, K) = f(n, K)-f(n, K-1),
            #    which also implies if we have one more egg with n moves and x-1 egges, we can have more C(n, x) floors solvable
            # => f(n, K) = C(n, K)+f(n, K-1) = C(n, K) + C(n, K-1) + ... + C(n, 1) + f(n, 0) = sum(C(n, k) for k in [1, K])
            # => all we have to do is to check sum(C(n, k) for k in [1, K]) >= N,
            #    if true, there must exist a 1-to-1 mapping from each F in [1, N] to each sucess and failure sequence of every C(n, k) combinations for k in [1, K]
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

