# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def percentageLetter(self, s, letter):
        """
        :type s: str
        :type letter: str
        :rtype: int
        """
        return 100*s.count(letter)//len(s)
