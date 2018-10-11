# Time:  O(n)
# Space: O(1)

class Solution(object):
    def escapeGhosts(self, ghosts, target):
        """
        :type ghosts: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        total = abs(target[0])+abs(target[1])
        return all(total < abs(target[0]-i)+abs(target[1]-j) for i, j in ghosts)

