# Time:  O(n * sqrt(n))
# Space: O(n + sqrt(n)) = O(n)

import collections


# math
class Solution(object):
    def countPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def gcd(x, y):
            while y:
                x, y = y, x%y
            return x
    
        idxs = collections.defaultdict(list)
        for i, x in enumerate(nums):
            idxs[x].append(i)
        result = 0
        for idx in idxs.itervalues():
            gcds = collections.Counter()
            for i in idx:
                gcd_i = gcd(i, k)
                result += sum(cnt for gcd_j, cnt in gcds.iteritems() if gcd_i*gcd_j%k == 0)
                gcds[gcd_i] += 1
        return result


# Time:  O(n^2)
# Space: O(n)
import collections


# brute force
class Solution2(object):
    def countPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        idxs = collections.defaultdict(list)
        for i, x in enumerate(nums):
            idxs[x].append(i)
        return sum(idx[i]*idx[j]%k == 0 for idx in idxs.itervalues() for i in xrange(len(idx)) for j in xrange(i+1, len(idx)))
