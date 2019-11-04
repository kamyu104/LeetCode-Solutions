# Time:  O(n)
# Space: O(1)

class Solution(object):
    def removeVowels(self, S):
        """
        :type S: str
        :rtype: str
        """
        lookup = set("aeiou")
        return "".join(c for c in S if c not in lookup)
