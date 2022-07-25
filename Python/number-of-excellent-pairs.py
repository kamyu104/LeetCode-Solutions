# Time:  O(n + (logn)^2) = O(n)
# Space: O(n + logn) = O(n)

import collections


# bit manipulation, freq table, combinatorics
class Solution(object):
    def countExcellentPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def popcount(x):
            return bin(x)[2:].count('1')

        cnt = collections.Counter(popcount(x) for x in set(nums))
        return sum(cnt[i]*cnt[j] for i in cnt.iterkeys() for j in cnt.iterkeys() if i+j >= k)


# Time:  O(nlogn)
# Space: O(n)
# bit manipulation, sort, two pointers
class Solution2(object):
    def countExcellentPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def popcount(x):
            return bin(x)[2:].count('1')

        sorted_cnts = sorted(popcount(x) for x in set(nums))
        result = 0
        left, right = 0, len(sorted_cnts)-1
        while left <= right:
            if sorted_cnts[left]+sorted_cnts[right] < k:
                left += 1
            else:
                result += 1+2*((right-1)-left+1)
                right -= 1
        return result
