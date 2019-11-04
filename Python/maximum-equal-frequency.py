# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def maxEqualFreq(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        count = collections.Counter()
        freq = [0 for _ in xrange(len(nums)+1)]
        for i, n in enumerate(nums, 1):
            freq[count[n]] -= 1
            freq[count[n]+1] += 1
            count[n] += 1
            c = count[n]
            if freq[c]*c == i and i < len(nums):
                result = i+1
            remain = i-freq[c]*c
            if freq[remain] == 1 and remain in [1, c+1]:
                result = i
        return result
