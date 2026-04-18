# Time:  precompute: O(rlog(logr))
#        runtime:    O(r + (n + q) * log(logr))
# Space: O(rlog(logr) + n)

# number theory, freq table
def precompute(r):
    factors = [[] for _ in xrange(r+1)]
    curr, k = 1, 0
    for i in xrange(2, len(factors)):
        if factors[i]:
            continue
        if curr*i <= r:
            curr *= i
            k += 1
        for j in xrange(i, len(factors), i):
            factors[j].append(i)
    return factors, k


MAX_NUMS = 50000
FACTORS, K = precompute(MAX_NUMS)
class Solution(object):
    def countGoodSubseq(self, nums, p, queries):
        """
        :type nums: List[int]
        :type p: int
        :type queries: List[List[int]]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        curr = [0]
        mx = max(max(nums), max(x for _, x in queries))
        cnt = [0]*(mx+1)
        cnt2 = [0]*(len(nums)+1)
        def update(x, d):
            if x%p:
                return
            for q in FACTORS[x//p]:
                cnt2[cnt[q]] -= 1
                cnt[q] += d
                cnt2[cnt[q]] += 1
            curr[0] += d

        def check():
            if curr[0] == 0 or cnt2[curr[0]]:
                return False
            if curr[0] != len(nums) or len(nums) > K:
                return True
            for i in xrange(len(nums)):
                update(nums[i], -1)
                found = (cnt2[curr[0]] == 0)
                update(nums[i], +1)
                if found:
                    return True
            return False

        result = 0
        for x in nums:
            update(x, +1)
        for i, x in queries:
            update(nums[i], -1)
            nums[i] = x
            update(nums[i], +1)
            if check():
                result += 1
        return result
