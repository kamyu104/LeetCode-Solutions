# Time:  O(nlogn)
# Space: O(n)

# prefix sum, sort, coordinate compression, fenwick tree
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
    def countRatioSubarrays(self, nums, a, b):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :rtype: int
        """
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+(b if nums[i]%2 == 0 else -a)
        val_to_idx = {x:i for i, x in enumerate(sorted(set(prefix)))}
        bit = BIT(len(val_to_idx))
        result = 0
        for i in xrange(len(prefix)):
            idx = val_to_idx[prefix[i]]
            result += i-bit.query(idx-1)
            bit.add(idx, 1)
        return result
