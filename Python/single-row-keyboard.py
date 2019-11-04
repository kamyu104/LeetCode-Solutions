# Time:  O(n)
# Space: O(1)

class Solution(object):
    def calculateTime(self, keyboard, word):
        """
        :type keyboard: str
        :type word: str
        :rtype: int
        """
        lookup = {c:i for i, c in enumerate(keyboard)}
        result, prev = 0, 0
        for c in word:
            result += abs(lookup[c]-prev)
            prev = lookup[c]
        return result
