# Time:  O(n * sqrt(r)), r = max(nums)
# Space: O(sqrt(r))

import collections


# number theory
class Solution(object):
    def findValidSplit(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def factorize(x):
            result = []
            d = 2
            while d*d <= x:
                e = 0
                while x%d == 0:
                    x //= d
                    e += 1
                if e:
                    result.append([d, e])
                d += 1 if d == 2 else 2
            if x > 1:
                result.append([x, 1])
            return result
        
        right = collections.Counter()
        for x in reversed(nums):
            for p, c in factorize(x):
                right[p] += c
        left = collections.Counter()
        cnt = 0
        for i in xrange(len(nums)-1):
            for p, c in factorize(nums[i]):
                if not left[p]:
                    cnt += 1
                left[p] += c
                right[p] -= c
                if not right[p]:
                    cnt -= 1
            if not cnt:
                return i
        return -1
