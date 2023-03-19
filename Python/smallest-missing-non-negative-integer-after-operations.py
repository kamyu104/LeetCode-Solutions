# Time:  O(n)
# Space: O(k), k = value

import collections


# freq table
class Solution(object):
    def findSmallestInteger(self, nums, value):
        """
        :type nums: List[int]
        :type value: int
        :rtype: int
        """
        cnt = collections.Counter(x%value for x in nums)
        mn = min((cnt[i], i) for i in xrange(value))[1]
        return value*cnt[mn]+mn
        

# Time:  O(n)
# Space: O(k), k = value
import collections


# freq table
class Solution2(object):
    def findSmallestInteger(self, nums, value):
        """
        :type nums: List[int]
        :type value: int
        :rtype: int
        """
        cnt = collections.Counter(x%value for x in nums)
        for i in xrange(len(nums)+1):
            if not cnt[i%value]:
                return i
            cnt[i%value] -= 1
