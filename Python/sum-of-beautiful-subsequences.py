# Time:  precompute: O(rlogr), r = max_nums
#        runtime:    O(mx + nlogr * (log(nlogr) + logn)), mx = max(nums)
# Space: O(rlogr)

# number theory, bit, fenwick tree
MOD = 10**9+7
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] = (self.__bit[i]+val) % MOD
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret = (ret+self.__bit[i]) % MOD
            i -= (i & -i)
        return ret


def factors(n):  # Time: O(nlogn)
    result = [[] for _ in xrange(n+1)]
    for i in xrange(1, n+1):
        for j in range(i, n+1, i):
            result[j].append(i)
    return result


def phi_sieve(n):  # Time: O(nlog(logn))
    phi = range(n+1)
    for i in xrange(2, n+1):
        if phi[i] != i:
            continue
        for j in xrange(i, n+1, i):
            phi[j] -= phi[j]//i
    return phi


MAX_NUM = 7 * 10**4
FACTORS = factors(MAX_NUM)
PHI = phi_sieve(MAX_NUM)
class Solution(object):
    def totalBeauty(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def count(arr):
            for i, x in enumerate(sorted(arr)):  # coordinate compression
                val_to_idx[x] = i
            bit = BIT(len(arr))
            for x in arr:
                bit.add(val_to_idx[x], bit.query(val_to_idx[x]-1)+1)
            return bit.query(len(arr)-1)

        mx = max(nums)
        val_to_idx = [0]*(mx+1)
        lookup = [[] for _ in xrange(mx+1)]
        for x in nums:
            for d in FACTORS[x]:
                lookup[d].append(x)
        return reduce(lambda accu, x: (accu+x)%MOD, (PHI[g]*count(lookup[g]) for g in reversed(xrange(1, mx+1))), 0)


# Time:  precompute: O(rlogr), r = max_nums
#        runtime:    O(mx * log(mx) + nlogr * (log(nlogr) + logn)), mx = max(nums)
# Space: O(rlogr)
# number theory, bit, fenwick tree
class Solution2(object):
    def totalBeauty(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def count(arr):
            val_to_idx = {x:i for i, x in enumerate(sorted(set(arr)))}  # coordinate compression
            bit = BIT(len(val_to_idx))
            for x in arr:
                bit.add(val_to_idx[x], bit.query(val_to_idx[x]-1)+1)
            return bit.query(len(val_to_idx)-1)

        mx = max(nums)
        lookup = [[] for _ in xrange(mx+1)]
        for x in nums:
            for d in FACTORS[x]:
                lookup[d].append(x)
        result = 0
        cnt = [0]*(mx+1)
        for g in reversed(xrange(1, mx+1)):
            cnt[g] = count(lookup[g])
            for ng in xrange(g+g, mx+1, g):
                cnt[g] -= cnt[ng]
            result = (result+g*cnt[g])%MOD
        return result
