# Time:  O(nlogn)
# Space: O(1)

# Same problem from https://codingcompetitions.withgoogle.com/codejam/round/00000000004330f6/0000000000432f33

import itertools
import operator


class Solution(object):
    def minProductSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def inner_product(vec1, vec2):
            return sum(itertools.imap(operator.mul, vec1, vec2))


        nums1.sort()
        nums2.sort(reverse=True)
        return inner_product(nums1, nums2)
