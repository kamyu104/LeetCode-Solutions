# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        lookup = {}
        result = float("inf")
        for i, x in enumerate(cards):
            if x in lookup:
                result = min(result, i-lookup[x]+1)
            lookup[x] = i
        return result if result != float("inf") else -1
