# Time:  O(n + 26)
# Space: O(26)

# freq table, two pointers, sliding window
class Solution(object):
    def numberOfSubstrings(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        cnt = [0]*26
        result = left = 0
        for right in xrange(len(s)):
            cnt[ord(s[right])-ord('a')] += 1
            while cnt[ord(s[right])-ord('a')] == k:
                result += (len(s)-1)-right+1
                cnt[ord(s[left])-ord('a')] -= 1
                left += 1
        return result
