# Time:  O(n)
# Space: O(1)

import itertools
import re


class Solution(object):
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ranges = []
        if not nums:
            return ranges

        start, end = nums[0], nums[0]
        for i in xrange(1, len(nums) + 1):
            if i < len(nums) and nums[i] == end + 1:
                end = nums[i]
            else:
                interval = str(start)
                if start != end:
                    interval += "->" + str(end)
                ranges.append(interval)
                if i < len(nums):
                    start = end = nums[i]

        return ranges

# Time:  O(n)
# Space: O(n)
class Solution2(object):
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        return [re.sub('->.*>', '->', '->'.join(repr(n) for _, n in g))
            for _, g in itertools.groupby(enumerate(nums), lambda i_n: i_n[1]-i_n[0])]

