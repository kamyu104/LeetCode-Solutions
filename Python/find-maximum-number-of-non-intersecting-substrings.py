# Time:  O(n)
# Space: O(26)

# greedy, hash table
class Solution(object):
    def maxSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        L = 4
        result = 0
        lookup = {}
        for i, c in enumerate(word):
            if c not in lookup:
                lookup[c] = i
            elif i-lookup[c]+1 >= L:
                result += 1
                lookup.clear()
        return result
