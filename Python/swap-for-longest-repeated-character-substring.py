# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        K = 1
        result = 0
        total_count, count = collections.Counter(), collections.Counter()
        left, max_count = 0, 0
        for i in xrange(len(text)):
            total_count[text[i]] += 1
            count[text[i]] += 1
            max_count = max(max_count, count[text[i]])
            if i-left+1 - max_count > K:
                count[text[left]] -= 1
                left += 1
            result = max(result, min(i-left+1, total_count[text[i]]))
        return result


    
# Time:  O(n)
# Space: O(n)
import itertools


class Solution2(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        A = [[c, len(list(group))] for c, group in itertools.groupby(text)]
        total_count = collections.Counter(text)
        result = max(min(l+1, total_count[c]) for c, l in A)
        for i in xrange(1, len(A)-1):
            if A[i-1][0] == A[i+1][0] and A[i][1] == 1:
                result = max(result, min(A[i-1][1] + 1 + A[i+1][1], total_count[A[i+1][0]]))
        return result
