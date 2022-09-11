# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, left = 1, 0
        lookup = {}
        for i, x in enumerate(s):
            if x in lookup and lookup[x] >= left:
                left = i
                result += 1
            lookup[x] = i
        return result
