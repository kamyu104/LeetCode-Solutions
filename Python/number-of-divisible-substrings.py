# Time:  O(d * n)
# Space: O(n)

import collections


# prefix sum, freq table
class Solution(object):
    def countDivisibleSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        result = 0
        for d in xrange(1, 10):
            prefix = 0
            cnt = collections.Counter([0+d*(-1+1)])
            for i, x in enumerate(word):
                prefix += (ord(x)-ord('a')+1)//3+1
                result += cnt[prefix-d*(i+1)]
                cnt[prefix-d*(i+1)] += 1
        return result
