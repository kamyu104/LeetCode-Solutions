# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def trimTrailingVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        VOWELS = "aeiou"
        def f(x):
            return 1<<(ord(x)-ord('a'))

        mask = reduce(lambda accu, x: accu|x, map(f, VOWELS), 0)
        i = next((i for i in reversed(xrange(len(s))) if not f(s[i])&mask), -1)
        return s[:i+1]


# Time:  O(n)
# Space: O(1)
# string
class Solution2(object):
    def trimTrailingVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        VOWELS = "aeiou"
        i = next((i for i in reversed(xrange(len(s))) if s[i] not in VOWELS), -1)
        return s[:i+1]
