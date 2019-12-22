# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        count = collections.Counter(nums)
        for num in sorted(count.keys()):
            c = count[num]
            if not c:
                continue
            for i in xrange(num, num+k):
                if count[i] < c:
                    return False
                count[i] -= c
        return True
