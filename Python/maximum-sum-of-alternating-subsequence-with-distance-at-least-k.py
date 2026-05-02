# Time:  O(nlogn)
# Space: O(n)

# sort, coordinate compression, fenwick tree, sliding window, dp
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] = max(self.__bit[i], val)  # modified
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret = max(ret, self.__bit[i])  # modified
            i -= (i & -i)
        return ret


class Solution(object):
    def maxAlternatingSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        val_to_idx = {x:i for i, x in enumerate(sorted(set(nums)))}
        bit = [BIT(len(val_to_idx)) for _ in xrange(2)]
        dp = [[0]*len(nums) for _ in xrange(2)]
        for i in xrange(len(nums)):
            if i-k >= 0:
                idx = val_to_idx[nums[i-k]]
                bit[0].add(idx, dp[0][i-k])
                bit[1].add((len(val_to_idx)-1)-idx, dp[1][i-k])
            idx = val_to_idx[nums[i]]
            dp[1][i] = bit[0].query(idx-1)+nums[i]
            dp[0][i] = bit[1].query(((len(val_to_idx)-1)-idx)-1)+nums[i]
        return max(max(dp[0]), max(dp[1]))
