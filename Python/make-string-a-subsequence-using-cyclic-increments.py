# Time:  O(n)
# Space: O(1)

# greedy, two pointers
class Solution(object):
    def canMakeSubsequence(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: bool
        """
        i = 0
        for c in str1:
            if (ord(str2[i])-ord(c))%26 > 1:
                continue
            i += 1
            if i == len(str2):
                return True
        return False
