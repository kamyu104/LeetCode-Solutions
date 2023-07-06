# Time:  O(n)
# Space: O(1)

# two pointers, sliding window
class Solution(object):
    def numberOfSpecialSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = left = 0
        lookup = [-1]*26
        for right in xrange(len(s)):
            if lookup[ord(s[right])-ord('a')] >= left:
                left = lookup[ord(s[right])-ord('a')]+1
            lookup[ord(s[right])-ord('a')] = right
            result += (right-left+1)
        return result


# Time:  O(n)
# Space: O(1)
# two pointers, sliding window
class Solution2(object):
    def numberOfSpecialSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = left = 0
        lookup = [False]*26
        for right in xrange(len(s)):
            while lookup[ord(s[right])-ord('a')]:
                lookup[ord(s[left])-ord('a')] = False
                left += 1
            lookup[ord(s[right])-ord('a')] = True
            result += (right-left+1)
        return result
