# Time:  O(nlogc), c is the count of unique characters.
# Space: O(c)

from collections import defaultdict
from heapq import heappush, heappop

class Solution(object):
    def rearrangeString(self, str, k):
        """
        :type str: str
        :type k: int
        :rtype: str
        """
        if k == 0:
            return str

        cnts = defaultdict(int)
        for c in str:
            cnts[c] += 1

        heap = []
        for c, cnt in cnts.iteritems():
            heappush(heap, [-cnt, c])
        
        result = []
        while heap:
            used_cnt_chars = []
            for _ in xrange(min(k, len(str) - len(result))):
                if not heap:
                    return ""
                cnt_char = heappop(heap)
                result.append(cnt_char[1])
                cnt_char[0] += 1
                if cnt_char[0] < 0:
                    used_cnt_chars.append(cnt_char)
            for cnt_char in used_cnt_chars:
                heappush(heap, cnt_char)

        return "".join(result)
