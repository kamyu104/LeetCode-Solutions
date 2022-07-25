# Time:  O(n)
# Space: O(1)

# hash table
class Solution(object):
    def repeatedCharacter(self, s):
        """
        :type s: str
        :rtype: str
        """
        lookup = set()
        for c in s:
            if c in lookup:
                break
            lookup.add(c)
        return c
