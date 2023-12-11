# Time:  O(n)
# Space: O(n)

# hash table, combinatorics
class Solution(object):
    def numberOfGoodPartitions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        lookup = {x:i for i, x in enumerate(nums)}
        result = 1
        right = cnt = 0
        for left, x in enumerate(nums):
            if left == right+1:
                cnt += 1
            right = max(right, lookup[x])
        return pow(2, cnt, MOD)
