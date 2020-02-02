# Time:  O(n)
# Space: O(n)

import collections

        
class Solution(object):
    def minSetSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        counting_sort = [0]*len(arr)
        count = collections.Counter(arr)
        for c in count.itervalues():
            counting_sort[c-1] += 1
        result, total = 0, 0
        for c in reversed(xrange(len(arr))):
            for _ in xrange(counting_sort[c]):
                result += 1
                total += c+1
                if total*2 >= len(arr):
                    return result
        return result
