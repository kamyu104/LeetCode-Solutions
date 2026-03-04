# Time:  O(nlogr), r = max(nums)
# Space: O(1)

# bitmasks, greedy
class Solution(object):
    def minimumOR(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        mx = max(x for row in grid for x in row)
        result = 0
        for i in reversed(xrange(mx.bit_length())):
            if any(all(x&(result|((1<<i)-1)) != x for x in row) for row in grid):
                result |= 1<<i
        return result
