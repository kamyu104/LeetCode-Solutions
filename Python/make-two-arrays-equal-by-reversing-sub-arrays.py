# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        return collections.Counter(target) == collections.Counter(arr)


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        target.sort(), arr.sort()
        return target == arr
