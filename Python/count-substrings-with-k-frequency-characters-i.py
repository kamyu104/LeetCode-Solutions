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
        def count():
            cnt = [0]*26
            result= left = 0
            for right in xrange(len(s)):
                cnt[ord(s[right])-ord('a')] += 1
                while cnt[ord(s[right])-ord('a')] == k:
                    cnt[ord(s[left])-ord('a')] -= 1
                    left += 1
                result += right-left+1
            return result
                
        return (len(s)+1)*len(s)//2-count()
