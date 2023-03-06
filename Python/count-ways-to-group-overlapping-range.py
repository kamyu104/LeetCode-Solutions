# Time:  O(nlogn)
# Space: O(1)

# sort, array
class Solution(object):
    def countWays(self, ranges):
        """
        :type ranges: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7

        ranges.sort()
        cnt = 0
        curr = float("-inf")
        for l, r in ranges:
            if l > curr:
                cnt += 1
            curr = max(curr, r)
        return pow(2, cnt, MOD)
