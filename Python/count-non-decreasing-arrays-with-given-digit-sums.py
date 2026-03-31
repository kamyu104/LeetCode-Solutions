# Time:  precompute: O(rlogr)
#        runtime:    O(n * r)
# Space: O(r)

# dp, prefix sum
MOD = 10**9+7
R = 5000
def total(x):
    result = 0
    while x:
        x, r = divmod(x, 10)
        result += r
    return result

def precompute(r):
    lookup = [[] for _ in xrange(r+1)]
    for i in xrange(len(lookup)):
        lookup[total(i)].append(i)
    return lookup

LOOKUP = precompute(R)
class Solution(object):
    def countArrays(self, digitSum):
        """
        :type digitSum: List[int]
        :rtype: int
        """
        dp = [(0, 1)]
        for x in digitSum:
            new_dp = []
            prefix = i = 0
            for v in LOOKUP[x]:
                while i < len(dp):
                    if dp[i][0] > v:
                        break
                    prefix = (prefix+dp[i][1])%MOD
                    i += 1
                if prefix:
                    new_dp.append((v, prefix))
            dp = new_dp
        return reduce(lambda accu, x: (accu+x)%MOD, (c for _, c in dp), 0)
