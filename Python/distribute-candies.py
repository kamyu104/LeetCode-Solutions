# Time:  O(n)
# Space: O(n)

class Solution(object):

    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        lookup = set(candies)
        return min(len(lookup), len(candies)/2)

