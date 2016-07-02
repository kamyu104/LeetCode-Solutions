# Time:  O(n)
# Space: O(n)

class Solution(object):
    def rearrangeString(self, str, k):
        """
        :type str: str
        :type k: int
        :rtype: str
        """
        cnts = [0] * 26;
        for c in str:
            cnts[ord(c) - ord('a')] += 1

        sorted_cnts = []
        for i in xrange(26):
            sorted_cnts.append((cnts[i], chr(i + ord('a'))))
        sorted_cnts.sort(reverse=True)

        max_cnt = sorted_cnts[0][0]
        blocks = [[] for _ in xrange(max_cnt)]
        i = 0
        for cnt in sorted_cnts:
            for _ in xrange(cnt[0]):
                blocks[i].append(cnt[1])
                i = (i + 1) % max(cnt[0], max_cnt - 1)

        for i in xrange(max_cnt-1):
            if len(blocks[i]) < k:
                return ""

        return "".join(map(lambda x : "".join(x), blocks))


# Time:  O(nlogc), c is the count of unique characters.
# Space: O(c)
from collections import defaultdict
from heapq import heappush, heappop
class Solution2(object):
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
