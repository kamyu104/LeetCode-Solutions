# Time:  O(nlogn)
# Space: O(n)

# sort, coordinate compression, fenwick tree
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


class Solution(object):
    def countSmallerOppositeParity(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        val_to_idx = {x:i for i, x in enumerate(sorted(set(nums)))}
        bit = [BIT(len(val_to_idx)) for _ in xrange(2)]
        result = [0]*len(nums)
        for i in reversed(xrange(len(nums))):
            idx = val_to_idx[nums[i]]
            result[i] = bit[1^(nums[i]%2)].query(idx-1)
            bit[nums[i]%2].add(idx, 1)
        return result
