# Time:  precompute: O((logr) * log(logr) + log*(r) * (logr)) = O((logr) * log(logr)), r = max(n)
#        runtime:    O(nlogr + max_k * n + nlogn + qlogn)
# Space: O(logr + max_k * n)

# fenwick tree
def popcount(x):
    return bin(x).count('1')


def ceil_log2(x):
    return (x-1).bit_length()


class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret


MAX_N = 10**15
MAX_BIT_LEN = MAX_N.bit_length()
D = [0]*(MAX_BIT_LEN+1)
for i in xrange(2, MAX_BIT_LEN+1):
    D[i] = D[popcount(i)]+1
MAX_K = 0
while MAX_N != 1:  # O(log*(MAX_N)) times
    MAX_N = ceil_log2(MAX_N)
    MAX_K += 1
class Solution(object):
    def popcountDepth(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def count(x):
            return D[popcount(x)]+1 if x != 1 else 0
        
        bit = [BIT(len(nums)) for _ in xrange(MAX_K+1)]
        for i in xrange(len(nums)):
            bit[count(nums[i])].add(i, +1)
        result = []
        for q in queries:
            if q[0] == 1:
                _, l, r, k = q
                assert(k < len(bit))
                result.append(bit[k].query(r)-bit[k].query(l-1))
            else:
                _, i, x = q
                old_d = count(nums[i])
                new_d = count(x)
                if new_d != old_d:
                    bit[old_d].add(i, -1)
                    bit[new_d].add(i, +1)
                nums[i] = x
        return result
