# Time:  O(n), k is the number of distinct barcodes
# Space: O(k)

import collections
import itertools


class Solution(object):
    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """
        k = 2
        cnts = collections.Counter(barcodes)
        bucket_cnt = max(cnts.itervalues())
        result = [0]*len(barcodes)
        i = (len(barcodes)-1)%k
        for c in itertools.chain((c for c, v in cnts.iteritems() if v == bucket_cnt), (c for c, v in cnts.iteritems() if v != bucket_cnt)):
            for _ in xrange(cnts[c]):
                result[i] = c
                i += k
                if i >= len(result):
                    i = (i-1)%k
        return result

    
# Time:  O(n + klogk), k is the number of distinct barcodes
# Space: O(k)
import collections


class Solution2(object):
    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """
        cnts = collections.Counter(barcodes)
        sorted_cnts = [[v, k] for k, v in cnts.iteritems()]
        sorted_cnts.sort(reverse=True)

        i = 0
        for v, k in sorted_cnts:
            for _ in xrange(v):
                barcodes[i] = k
                i += 2
                if i >= len(barcodes):
                    i = 1
        return barcodes
