# Time:  precompute: O(t + 26)
#        runtime:    O(n)
# Space: O(t + 26)

# precompute, dp
MOD = 10**9+7
MAX_T = 10**5
DP = [0]*(MAX_T+26)
for i in xrange(26):
    DP[i] = 1
for i in xrange(26, len(DP)):
    DP[i] = (DP[i-26]+DP[(i-26)+1])%MOD
class Solution(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        return reduce(lambda accu, x: (accu+x)%MOD, (DP[((ord(x)-ord('a'))+t)] for x in s), 0)


# Time:  O(n + t + 26)
# Space: O(26)
# dp
class Solution2(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [1]*26
        for i in xrange(26, (ord(max(s))-ord('a')+t)+1):
            dp[i%26] = (dp[(i-26)%26]+dp[((i-26)+1)%26])%MOD
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[((ord(x)-ord('a'))+t)%26] for x in s), 0)


# Time:  O(n + 26^3 * logt)
# Space: O(26^2)
import itertools


# matrix fast exponentiation
class Solution3(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a*b % MOD for a, b in itertools.izip(row, col)) % MOD for col in ZB] for row in A]
 
        def matrix_expo(A, K):
            result = [[int(i == j) for j in xrange(len(A))] for i in xrange(len(A))]
            while K:
                if K % 2:
                    result = matrix_mult(result, A)
                A = matrix_mult(A, A)
                K /= 2
            return result

        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        nums = [1]*26
        nums[-1] = 2
        matrix = [[0]*26 for _ in xrange(26)]
        for i in xrange(len(nums)):
            for j in xrange(1, nums[i]+1):
                matrix[i][(i+j)%26] = 1
        matrix_pow_t = matrix_expo(matrix, t)
        return reduce(lambda accu, x: (accu+x)%MOD, matrix_mult([cnt], matrix_pow_t)[0], 0)


# Time:  O(n + t * 26)
# Space: O(26)
# dp
class Solution4(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        MOD = 10**9+7
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        for _ in xrange(t):
            new_cnt = [0]*26
            for i in xrange(26):
                new_cnt[(i+1)%26] = (new_cnt[(i+1)%26]+cnt[i])%MOD
                if i == 25:
                    new_cnt[(i+2)%26] = (new_cnt[(i+2)%26]+cnt[i])%MOD
            cnt = new_cnt
        return reduce(lambda accu, x: (accu+x)%MOD, cnt, 0)
