# Time:  O(n)
# Space: O(1)

import itertools


# bit manipulation
class Solution(object):
    def getSneakyNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def f(check):
            return reduce(lambda accu, x: accu^x, (x for x in itertools.chain(nums, xrange(n)) if check(x)), 0)

        n = len(nums)-2
        x_xor_y = f(lambda _: True)
        bit = x_xor_y&-x_xor_y
        return [f(lambda x: x&bit == 0), f(lambda x: x&bit != 0)]
