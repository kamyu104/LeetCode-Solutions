# Time:  O(n)
# Space: O(1)

class Solution(object):
    def stoneGameVIII(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        for i in xrange(len(stones)-1):
            stones[i+1] += stones[i]
        return reduce(lambda curr, i: max(curr, stones[i]-curr), reversed(xrange(1, len(stones)-1)), stones[-1])
