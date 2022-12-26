# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxJump(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        return stones[1]-stones[0] if len(stones) == 2 else max(stones[i+2]-stones[i] for i in xrange(len(stones)-2))
