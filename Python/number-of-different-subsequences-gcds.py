# Time:  O(n + m * (1 + 1/2 + 1/3 + ... + 1/m)) = O(n + mlogm), m is max of nums
# Space: O(n)

import fractions


class Solution(object):
    def countDifferentSubsequenceGCDs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num, nums_set = max(nums), set(nums)
        result = 0
        for i in xrange(1, max_num+1):
            d = 0
            for x in xrange(i, max_num+1, i):
                if x not in nums_set:
                    continue
                d = fractions.gcd(d, x)
                if d == i:
                    result += 1
                    break
        return result
