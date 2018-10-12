# Time:  O(nloga) = O(n), a is the size of alphabet
# Space: O(a) = O(1)

import collections
import heapq


class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        counts = collections.Counter(S)
        if any(v > (len(S)+1)/2 for k, v in counts.iteritems()):
            return ""

        result = []
        max_heap = []
        for k, v in counts.iteritems():
            heapq.heappush(max_heap, (-v, k))
        while len(max_heap) > 1:
            count1, c1 = heapq.heappop(max_heap)
            count2, c2 = heapq.heappop(max_heap)
            if not result or c1 != result[-1]:
                result.extend([c1, c2])
                if count1+1: heapq.heappush(max_heap, (count1+1, c1))
                if count2+1: heapq.heappush(max_heap, (count2+1, c2))
        return "".join(result) + (max_heap[0][1] if max_heap else '')

