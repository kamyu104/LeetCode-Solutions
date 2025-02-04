# Time:  O(n)
# Space: O(1)

# freq table
class Solution(object):
    def findValidPair(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*9
        for x in s:
            cnt[ord(x)-ord('1')] += 1
        for i in xrange(len(s)-1):
            if s[i] != s[i+1] and cnt[ord(s[i])-ord('1')] == ord(s[i])-ord('0') and cnt[ord(s[i+1])-ord('1')] == ord(s[i+1])-ord('0'):
                return s[i:i+2]
        return ""
