# Time:  O(n)
# Space: O(1)

# simulation
class Solution(object):
    def totalReplacements(self, ranks):
        """
        :type ranks: List[int]
        :rtype: int
        """
        result = -1
        mn = float("inf")
        for x in ranks:
            if x >= mn:
                continue
            mn = x
            result += 1
        return result
