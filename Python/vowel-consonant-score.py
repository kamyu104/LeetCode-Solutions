# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def vowelConsonantScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        VOWELS = "aeiou"
        v = c = 0
        for x in s:
            if x in VOWELS:
                v += 1
            elif x.isalpha():
                c += 1
        return v//c if c else 0
