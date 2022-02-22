# Time:  O(nlogk + sqrt(k)^2) = O(nlogk + k)
# Space: O(sqrt(k)), number of factors of k is at most sqrt(k)

import collections


# math, number theory
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
    
        cnt = collections.Counter()
        for x in nums:
            cnt[gcd(x, k)] += 1
        result = 0
        for x in cnt.iterkeys():
            for y in cnt.iterkeys():
                if x > y or x*y%k:
                    continue
                result += cnt[x]*cnt[y] if x != y else cnt[x]*(cnt[x]-1)//2
        return result


# Time:  O(nlogk + n * sqrt(k))
# Space: O(sqrt(k)), number of factors of k is at most sqrt(k)
import collections


# math, number theory
class Solution2(object):
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

        result = 0
        gcds = collections.Counter()
        for x in nums:
            gcd_i = gcd(x, k)
            result += sum(cnt for gcd_j, cnt in gcds.iteritems() if gcd_i*gcd_j%k == 0)
            gcds[gcd_i] += 1
        return result
