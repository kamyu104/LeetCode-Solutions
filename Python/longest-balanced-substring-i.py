# Time:  O(a * n^2), a = len(set(s))
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
            for j in xrange(i, len(s)):
                cnt[s[j]] += 1
                if (j-i+1)%len(cnt) == 0 and (j-i+1)//len(cnt) == max(cnt.itervalues()):
                    result = max(result, j-i+1)
        return result


# Time:  O(26 * n^2)
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
            unique = 0
            for j in xrange(i, len(s)):
                if cnt[ord(s[j])-ord('a')] == 0:
                    unique += 1
                cnt[ord(s[j])-ord('a')] += 1
                if (j-i+1)%unique == 0 and (j-i+1)//unique == max(cnt):
                    result = max(result, j-i+1)
        return result
