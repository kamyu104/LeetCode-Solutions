# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        result, left = 0, 0
        lookup = {}
        for right in xrange(len(s)):
            if s[right] in lookup:
                left = max(left, lookup[s[right]]+1)
            lookup[s[right]] = right
            result = max(result, right-left+1)
        return result
