# Time:  O(nlogn)
# Space: O(n)

# sort, coordinate compression, fenwick tree, sliding window
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
    def minInversionCount(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        val_to_idx = {x:i for i, x in enumerate(sorted(set(nums)))}
        bit = BIT(len(val_to_idx))
        result = float("inf")
        cnt = 0
        for i in xrange(len(nums)):
            cnt += bit.query(len(val_to_idx)-1)-bit.query(val_to_idx[nums[i]])
            bit.add(val_to_idx[nums[i]], +1)
            if i-(k-1) < 0:
                continue
            result = min(result, cnt)
            bit.add(val_to_idx[nums[i-(k-1)]], -1)
            cnt -= bit.query(val_to_idx[nums[i-(k-1)]]-1)
        return result
