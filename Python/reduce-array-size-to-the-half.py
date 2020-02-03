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
            if not counting_sort[c]:
                continue
            count = min(counting_sort[c],
                        ((len(arr)+1)//2 - total - 1)//(c+1) + 1)
            result += count
            total += count*(c+1)
            if total >= (len(arr)+1)//2:
                break
        return result
