# Time:  O(n)
# Space: O(1)

class Solution(object):
    def removePalindromeSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        def is_palindrome(s):
            for i in xrange(len(s)//2):
                if s[i] != s[-1-i]:
                    return False
            return True
        
        return 2 - is_palindrome(s) - (s == "")
