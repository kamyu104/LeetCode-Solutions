# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def minimumSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = left = 0
        for right in xrange(len(s)):
            if s[right] != '0':
                continue
            result += right-left
            left += 1
        return result


# Time:  O(n)
# Space: O(1)
# two pointers
class Solution2(object):
    def minimumSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        left, right = 0, len(s)-1
        while left < right:
            if left < len(s) and s[left] != '1':
                left += 1
                continue
            if right >= 0 and s[right] != '0':
                right -= 1
                continue
            result += right-left
            left += 1
            right -= 1
        return result
