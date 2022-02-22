# Time:  O(nlogk + sqrt(k)^2) = O(nlogk + k)
# Space: O(sqrt(k)), number of factors of k is at most sqrt(k)

import collections


# math, combinatorics
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
    
        cnt = collections.defaultdict(int)
        for x in nums:
            x = gcd(x, k)
            cnt[x] += 1
        result = 0
        for x in cnt.iterkeys():
            for y in cnt.iterkeys():
                if x > y or x*y%k:
                    continue
                result += cnt[x]*cnt[y] if x != y else cnt[x]*(cnt[x]-1)//2
        return result
