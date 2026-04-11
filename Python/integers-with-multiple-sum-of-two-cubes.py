# Time:  O(n^(2/3) * logn)
# Space: O(n^(2/3))

import collections


# freq table
class Solution(object):
    def findGoodIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        cnt = collections.defaultdict(int)
        for i in xrange(1, n+1):
            if i**3 > n:
                break
            for j in xrange(i, (n-i**3)+1):
                if j**3 > n-i**3:
                    break
                cnt[i**3+j**3] += 1
        return sorted(k for k, v in cnt.iteritems() if v >= 2)
