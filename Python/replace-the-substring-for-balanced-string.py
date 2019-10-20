# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def balancedString(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = collections.Counter(s)
        result = len(s) 
        left = 0
        for right in xrange(len(s)):
            count[s[right]] -= 1
            while left < len(s) and \
                  all(v <= len(s)//4 for v in count.itervalues()):
                result = min(result, right-left+1)
                count[s[left]] += 1
                left += 1
        return result
