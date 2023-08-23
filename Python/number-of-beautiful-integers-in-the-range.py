# Time:  O(n^2 * k), n = len(str(high))
# Space: O(n^2 * k)

# memoization (faster but more space)
class Solution(object):
    def numberOfBeautifulIntegers(self, low, high, k):
        """
        :type low: int
        :type high: int
        :type k: int
        :rtype: int
        """
        def f(x):
            arr = map(int, str(x))
            lookup = [[[[[-1]*k for _ in xrange(2*len(arr)+1)] for _ in xrange(2)] for _ in xrange(2)] for _ in xrange(len(arr))]
            def memoization(i, zero, tight, diff, total):
                if i == len(arr):
                    return zero == diff == total == 0
                if lookup[i][zero][tight][diff][total] == -1:
                    result = 0
                    for d in xrange((arr[i] if tight else 9)+1):
                        new_zero = int(zero and d == 0)
                        new_tight = int(tight and d == arr[i])
                        new_diff = diff+((1 if d%2 == 0 else -1) if not new_zero else 0)
                        new_total = (total*10+d)%k
                        result += memoization(i+1, new_zero, new_tight, new_diff, new_total)
                    lookup[i][zero][tight][diff][total] = result
                return lookup[i][zero][tight][diff][total]
    
            return memoization(0, 1, 1, 0, 0)

        return f(high)-f(low-1)


# Time:  O(n^2 * k), n = len(str(high))
# Space: O(n * k)
# dp (slower but less space)
class Solution2(object):
    def numberOfBeautifulIntegers(self, low, high, k):
        """
        :type low: int
        :type high: int
        :type k: int
        :rtype: int
        """
        def f(x):
            arr = map(int, str(x))
            dp = [[[[0]*k for _ in xrange(2*len(arr)+1)] for _ in xrange(2)] for _ in xrange(2)]
            for tight in xrange(2):
                dp[0][tight][0][0] = 1
            for i in reversed(xrange(len(arr))):
                new_dp = [[[[0]*k for _ in xrange(2*len(arr)+1)] for _ in xrange(2)] for _ in xrange(2)]
                for zero in xrange(2):
                    for tight in xrange(2):
                        for d in xrange((arr[i] if tight else 9)+1):
                            new_zero = int(zero and d == 0)
                            new_tight = int(tight and d == arr[i])
                            for diff in xrange(-len(arr), len(arr)+1):
                                new_diff = diff+((1 if d%2 == 0 else -1) if not new_zero else 0)
                                for total in xrange(k):
                                    new_total = (total*10+d)%k
                                    new_dp[zero][tight][diff][total] += dp[new_zero][new_tight][new_diff][new_total]
                dp = new_dp
            return dp[1][1][0][0]

        return f(high)-f(low-1)
