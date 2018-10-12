# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        A = map(int, str(N))
        invalid, diff = set([3, 4, 7]), set([2, 5, 6, 9])
        def dp(A, i, is_prefix_equal, is_good, lookup):
            if i == len(A): return int(is_good)
            if (i, is_prefix_equal, is_good) not in lookup:
                result = 0
                for d in xrange(A[i]+1 if is_prefix_equal else 10):
                    if d in invalid: continue
                    result += dp(A, i+1,
                                 is_prefix_equal and d == A[i],
                                 is_good or d in diff,
                                 lookup)
                lookup[i, is_prefix_equal, is_good] = result
            return lookup[i, is_prefix_equal, is_good]

        lookup = {}
        return dp(A, 0, True, False, lookup)


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        INVALID, SAME, DIFF = 0, 1, 2
        same, diff = [0, 1, 8], [2, 5, 6, 9]
        dp = [0] * (N+1)
        dp[0] = SAME
        for i in xrange(N//10+1):
            if dp[i] != INVALID:
                for j in same:
                    if i*10+j <= N:
                        dp[i*10+j] = max(SAME, dp[i])
                for j in diff:
                    if i*10+j <= N:
                        dp[i*10+j] = DIFF
        return dp.count(DIFF)


# Time:  O(nlogn) = O(n), because O(logn) = O(32) by this input
# Space: O(logn) = O(1)
class Solution3(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        invalid, diff = set(['3', '4', '7']), set(['2', '5', '6', '9'])
        result = 0
        for i in xrange(N+1):
            lookup = set(list(str(i)))
            if invalid & lookup:
                continue
            if diff & lookup:
                result += 1
        return result


