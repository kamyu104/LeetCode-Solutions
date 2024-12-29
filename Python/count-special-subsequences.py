# Time:  O(n^2)
# Space: O(n^2)

import collections


# freq table
class Solution(object):
    def numberOfSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        result = 0
        for r in xrange(4, len(nums)-2):
            q = r-2
            for p in xrange((q-2)+1):
                cnt[float(nums[p])/nums[q]] += 1
            for s in xrange(r+2, len(nums)):
                result += cnt[float(nums[s])/nums[r]]
        return result


# Time:  O(n^2 * logr)
# Space: O(n^2)
import collections


# freq table, number theory
class Solution2(object):
    def numberOfSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a
    
        cnt = collections.defaultdict(int)
        result = 0
        for r in xrange(4, len(nums)-2):
            q = r-2
            for p in xrange((q-2)+1):
                g = gcd(nums[p], nums[q])
                cnt[nums[p]//g, nums[q]//g] += 1
            for s in xrange(r+2, len(nums)):
                g = gcd(nums[s], nums[r])
                result += cnt[nums[s]//g, nums[r]//g]
        return result
