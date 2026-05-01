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
        odd, even = BIT(len(val_to_idx)), BIT(len(val_to_idx))
        result = [0]*len(nums)
        for i in reversed(xrange(len(nums))):
            idx = val_to_idx[nums[i]]
            if nums[i]%2:
                result[i] = even.query(idx-1)
                odd.add(idx, 1)
            else:
                result[i] = odd.query(idx-1)
                even.add(idx, 1)
        return result
