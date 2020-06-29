# Time:  O(n)
# Space: O(k)

import collections


class Solution(object):
    def canArrange(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: bool
        """
        if len(arr)%2:
            return False
        count = collections.Counter(i%k for i in arr)
        return all((not i and not count[i]%2) or 
                   (i and count[i] == count[k-i])
                   for i in xrange(k))
