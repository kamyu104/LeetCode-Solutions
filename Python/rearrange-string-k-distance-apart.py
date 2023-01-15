# Time:  O(n)
# Space: O(c)

import collections
import itertools


class Solution(object):
    def rearrangeString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        if not k:
            return s
        cnts = collections.Counter(s)
        bucket_cnt = max(cnts.itervalues())
        if not ((bucket_cnt-1)*k+sum(x == bucket_cnt for x in cnts.itervalues()) <= len(s)):
            return ""
        result = [0]*len(s)
        i = (len(s)-1)%k
        for c in itertools.chain((c for c, v in cnts.iteritems() if v == bucket_cnt), (c for c, v in cnts.iteritems() if v != bucket_cnt)):
            for _ in xrange(cnts[c]):
                result[i] = c
                i += k
                if i >= len(result):
                    i = (i-1)%k
        return "".join(result)


# Time:  O(n)
# Space: O(n)
import collections
import itertools


# reference: https://codeforces.com/blog/entry/110184 1774B - Coloring
class Solution2(object):
    def rearrangeString(self, s, k):
        """
        :type str: str
        :type k: int
        :rtype: str
        """
        if not k:
            return s
        cnts = collections.Counter(s)
        bucket_cnt = (len(s)+k-1)//k
        if not (max(cnts.itervalues()) <= bucket_cnt and cnts.values().count(bucket_cnt) <= (len(s)-1)%k+1):
            return ""
        result = [0]*len(s)
        i = 0
        for c in itertools.chain((c for c, v in cnts.iteritems() if v == bucket_cnt),
                                 (c for c, v in cnts.iteritems() if v <= bucket_cnt-2),
                                 (c for c, v in cnts.iteritems() if v == bucket_cnt-1)):
            for _ in xrange(cnts[c]):
                result[i] = c
                i += k
                if i >= len(result):
                    i = i%k+1
        return "".join(result)


# Time:  O(n)
# Space: O(n)
import collections
import itertools


class Solution3(object):
    def rearrangeString(self, s, k):
        """
        :type str: str
        :type k: int
        :rtype: str
        """
        cnts = collections.Counter(s)
        bucket_cnt = max(cnts.itervalues())
        buckets = [[] for _ in xrange(bucket_cnt)]
        i = 0
        for c in itertools.chain((c for c, v in cnts.iteritems() if v == bucket_cnt),
                                 (c for c, v in cnts.iteritems() if v == bucket_cnt-1),
                                 (c for c, v in cnts.iteritems() if v <= bucket_cnt-2)):
            for _ in xrange(cnts[c]):
                buckets[i].append(c)
                i = (i+1) % max(cnts[c], bucket_cnt-1)
        if any(len(buckets[i]) < k for i in xrange(len(buckets)-1)):
            return ""
        return "".join(map(lambda x : "".join(x), buckets))


# Time:  O(nlogc), c is the count of unique characters.
# Space: O(c)
from collections import Counter
from heapq import heappush, heappop
class Solution4(object):
    def rearrangeString(self, s, k):
        """
        :type str: str
        :type k: int
        :rtype: str
        """
        if k <= 1:
            return s

        cnts = Counter(s)
        heap = []
        for c, cnt in cnts.iteritems():
            heappush(heap, [-cnt, c])

        result = []
        while heap:
            used_cnt_chars = []
            for _ in xrange(min(k, len(s) - len(result))):
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
