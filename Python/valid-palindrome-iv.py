# Time:  O(n)
# Space: O(1)

# string, two pointers
class Solution(object):
    def makePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return sum(s[i] != s[~i] for i in xrange(len(s)//2)) <= 2


# Time:  O(n)
# Space: O(1)
# string, two pointers
class Solution2(object):
    def makePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cnt = 0
        left, right = 0, len(s)-1
        while left < right:
            if s[left] != s[right]:
                cnt += 1
                if cnt > 2:
                    return False
            left += 1
            right -= 1
        return True
