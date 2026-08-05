# Time:  O(n)
# Space: O(n)

# line sweep, difference array, backward simulation
class Solution(object):
    def minInitialStrength(self, monsters, boosts):
        """
        :type monsters: List[int]
        :type boosts: List[List[int]]
        :rtype: int
        """
        diff = [0]*len(monsters)
        for l, r, v in boosts:
            diff[r] += v
            if l-1 >= 0:
                diff[l-1] -= v
        result = bonus = 0
        for i in reversed(xrange(len(monsters))):
            bonus += diff[i]
            result += monsters[i] if result else max(monsters[i]-bonus, 0)
        return result
