# Time:  O(nlogn)
# Space: O(n)

import collections


# rolling hash, binary search
class Solution(object):
    def smallestUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        B = 29
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def get_hash(l, r):
            return (prefix[r+1]-prefix[l]*base[r-l+1])%MOD if l <= r else 0

        def check(l):
            cnt = collections.defaultdict(int)
            for i in xrange(len(nums)-l+1):
                cnt[get_hash(i, i+l-1)] += 1
            return any(x == 1 for x in cnt.itervalues())
    
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(prefix)-1):
            prefix[i+1] = (prefix[i]*B+nums[i])%MOD
        base = [1]*(len(nums)+1)
        for i in xrange(len(base)-1):
            base[i+1] = (base[i]*B)%MOD
        return binary_search(1, len(nums)-1, check)
