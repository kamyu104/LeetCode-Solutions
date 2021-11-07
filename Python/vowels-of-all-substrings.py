# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countVowels(self, word):
        """
        :type word: str
        :rtype: int
        """
        VOWELS = set("aeiou")
        return sum((i+1) * (len(word)-i) for i, c in enumerate(word) if c in VOWELS)
