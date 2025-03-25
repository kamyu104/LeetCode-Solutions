# Time:  O(n * m)
# Space: O(1)

# prefix sum, greedy
class Solution(object):
    def minTime(self, skill, mana):
        """
        :type skill: List[int]
        :type mana: List[int]
        :rtype: int
        """
        result = 0
        for i in xrange(1, len(mana)):
            prefix = mx = 0
            for x in skill:
                prefix += x
                mx = max(mx, mana[i-1]*prefix-mana[i]*(prefix-x))
            result += mx
        result += mana[-1]*sum(skill)
        return result
