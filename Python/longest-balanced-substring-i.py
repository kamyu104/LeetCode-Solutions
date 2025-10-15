# Time:  O(n * (a + n))), a = len(set(s))
# Space: O(a)

import collections


# freq table
class Solution(object):
    def longestBalanced(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i in xrange(len(s)):
            cnt = collections.defaultdict(int)
            mx = 0
            for j in xrange(i, len(s)):
                cnt[s[j]] += 1
                mx = max(mx, cnt[s[j]])
                if (j-i+1)%len(cnt) == 0 and (j-i+1)//len(cnt) == mx:
                    result = max(result, j-i+1)
        return result


# Time:  O(n * (26 + n))
# Space: O(26)
# freq table
class Solution2(object):
    def longestBalanced(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i in xrange(len(s)):
            cnt = [0]*26
            mx = unique = 0
            for j in xrange(i, len(s)):
                if cnt[ord(s[j])-ord('a')] == 0:
                    unique += 1
                cnt[ord(s[j])-ord('a')] += 1
                mx = max(mx, cnt[ord(s[j])-ord('a')])
                if (j-i+1)%unique == 0 and (j-i+1)//unique == mx:
                    result = max(result, j-i+1)
        return result
