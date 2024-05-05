# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def isValid(self, word):
        """
        :type word: str
        :rtype: bool
        """
        VOWELS = "aeiou"

        if len(word) < 3:
            return False
        vowel = consonant = False
        for x in word:
            if x.isalpha():
                if x.lower() in VOWELS:
                    vowel = True
                else:
                    consonant = True
            elif not x.isdigit():
                return False
        return vowel and consonant
