# Time:  O(n)
# Space: O(1)
#
# Given a sorted integer array without duplicates,
# return the summary of its ranges.
#
# For example, given [0,1,2,4,5,7],
# return ["0->2","4->5","7"].
#

class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ranges = []
        if not nums:
            return ranges

        start, end = nums[0], nums[0]
        for num in nums:
            if num > end + 1:
                self.add_range(start, end, ranges)
                start, end = num, num
            else:
                end = num
            if num == nums[-1]:
                self.add_range(start, end, ranges)

        return ranges
    
    def add_range(self, start, end, ranges):
        if start != end:
            ranges.append("{}->{}".format(start, end))
        else:
            ranges.append("{}".format(start))

# Time:  O(n)
# Space: O(1)
class Solution2:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        return [re.sub('->.*>', '->', '->'.join(`n` for _, n in g))
            for _, g in itertools.groupby(enumerate(nums), lambda (i, n): n-i)]
