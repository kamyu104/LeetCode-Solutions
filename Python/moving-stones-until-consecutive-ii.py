# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def numMovesStonesII(self, stones):
        """
        :type stones: List[int]
        :rtype: List[int]
        """
        stones.sort()
        left, min_moves = 0, float("inf")
        max_moves = max(stones[-1]-stones[1], stones[-2]-stones[0]) - (len(stones)-2)
        for right in xrange(len(stones)):
            while stones[right]-stones[left]+1 > len(stones): # find window size <= len(stones)
                left += 1
            if len(stones)-(right-left+1) == 1 and stones[right]-stones[left]+1 == len(stones)-1:
                min_moves = min(min_moves, 2)  # case (1, 2, 3, 4), 7
            else:
                min_moves = min(min_moves, len(stones)-(right-left+1))  # move stones not in this window
        return [min_moves, max_moves]
