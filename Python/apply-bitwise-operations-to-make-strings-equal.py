# Time:  O(n)
# Space: O(1)

# constructive algorithms
class Solution(object):
    def makeStringsEqual(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: bool
        """
        return ('1' in s) == ('1' in target)
