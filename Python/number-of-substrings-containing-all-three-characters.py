# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, left = 0, [-1]*3
        for right, c in enumerate(s):
            left[ord(c)-ord('a')] = right
            result += min(left)+1
        return result


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, left, count = 0, 0, [0]*3
        for right, c in enumerate(s):
            count[ord(s[right])-ord('a')] += 1
            while all(count):
                count[ord(s[left])-ord('a')] -= 1
                left += 1
            result += left
        return result


# Time:  O(n)
# Space: O(1)
class Solution3(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, right, count = 0, 0, [0]*3
        for left, c in enumerate(s):
            while right < len(s) and not all(count):
                count[ord(s[right])-ord('a')] += 1
                right += 1
            if all(count):
                result += (len(s)-1) - (right-1) + 1
            count[ord(c)-ord('a')] -= 1
        return result
