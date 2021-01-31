# Time:  O(n)
# Space: O(n)

class Solution(object):
    def canEat(self, candiesCount, queries):
        """
        :type candiesCount: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        prefix = [0]*(len(candiesCount)+1)
        for i, c in enumerate(candiesCount):
            prefix[i+1] = prefix[i]+c
        return [prefix[t]//c < d+1 <= prefix[t+1]//1 for t, d, c in queries]
