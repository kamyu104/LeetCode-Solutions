# Time:  precompute: O(max_r^2 * log(max_r))
#        runtime:    O(n + r^2)
# Space: O(max_r^2)

# number theory, mobius function, principle of inclusion-exclusion
MOD = 10**9+7
MAX_NUM = 200
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

def lcm(a, b):
    return a//gcd(a, b)*b

POW2 = [1]*(MAX_NUM+1)  # Time: O(max_r)
for i in xrange(len(POW2)-1):
    POW2[i+1] = (POW2[i]*2)%MOD
POW3 = [1]*(MAX_NUM+1)
for i in xrange(len(POW3)-1):  # Time: O(max_r)
    POW3[i+1] = (POW3[i]*3)%MOD
LCM = [[0]*(MAX_NUM+1) for _ in xrange(MAX_NUM+1)]
for i in xrange(1, MAX_NUM+1):  # Time: O(max_r^2 * log(max_r))
    for j in xrange(i, MAX_NUM+1):
        LCM[i][j] = LCM[j][i] = lcm(i, j)
MU = [0]*(MAX_NUM+1)
MU[1] = 1
for i in xrange(1, MAX_NUM+1):  # Time: O(max_r * log(max_r))
    for j in xrange(i+i, MAX_NUM+1, i):
        MU[j] -= MU[i] 
class Solution(object):
    def subsequencePairCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def count(g):
            return reduce(lambda accu, x: (accu+x)%MOD, (MU[i]*MU[j]*f[i*g][j*g] for i in xrange(1, mx//g+1) for j in xrange(1, mx//g+1)), 0)
            
        mx = max(nums)
        cnt = [0]*(mx+1)
        for x in nums:
            cnt[x] += 1
        for i in xrange(1, mx+1):
            for j in xrange(i+i, mx+1, i):
                cnt[i] += cnt[j]
        f = [[0]*(mx+1) for _ in xrange(mx+1)]
        for g1 in xrange(1, mx+1):
            for g2 in xrange(g1, mx+1):
                l = LCM[g1][g2]
                c = cnt[l] if l < len(cnt) else 0
                c1, c2 = cnt[g1], cnt[g2]
                f[g1][g2] = f[g2][g1] = (POW3[c]*POW2[(c1-c)+(c2-c)]-POW2[c1]-POW2[c2]+1)%MOD
        return reduce(lambda accu, x: (accu+x)%MOD, (count(g) for g in xrange(1, mx+1)), 0)  # Time: O(mx^2 * (1 + 1/4 + 1/9 + ... + (1/mx)^2))) = O(mx^2 * pi^2/6), see https://en.wikipedia.org/wiki/Basel_problem


# Time:  O(n * r^2 * logr)
# Space: O(r^2)
import collections


# dp, number theory
class Solution2(object):
    def subsequencePairCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        dp = collections.defaultdict(int)
        dp[(0, 0)] = 1
        for x in nums:
            new_dp = collections.defaultdict(int)
            for (g1, g2), cnt in dp.items():
                ng1, ng2 = gcd(g1, x), gcd(g2, x)
                new_dp[(g1, g2)] = (new_dp[(g1, g2)]+cnt)%MOD
                new_dp[(ng1, g2)] = (new_dp[(ng1, g2)]+cnt)%MOD
                new_dp[(g1, ng2)] = (new_dp[(g1, ng2)]+cnt)%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (cnt for (g1, g2), cnt in dp.iteritems() if g1 == g2 > 0), 0)


# Time:  O(n * r^2 * logr)
# Space: O(r^2)
import collections


# dp, number theory
class SolutionTLE(object):
    def subsequencePairCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        mx = max(nums)
        dp = [[0]*(mx+1) for _ in xrange(mx+1)]
        dp[0][0] = 1
        for x in nums:
            new_dp = [row[:] for row in dp]
            for g1 in reversed(xrange(mx+1)):
                for g2 in reversed(xrange(mx+1)):
                    ng1, ng2 = gcd(g1, x), gcd(g2, x)
                    new_dp[ng1][g2] = (new_dp[ng1][g2]+dp[g1][g2])%MOD
                    new_dp[g1][ng2] = (new_dp[g1][ng2]+dp[g1][g2])%MOD
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (dp[g][g] for g in xrange(1, mx+1)), 0)
