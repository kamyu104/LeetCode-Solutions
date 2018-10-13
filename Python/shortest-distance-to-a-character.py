# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        result = [len(S)] * len(S)
        prev = -len(S)
        for i in itertools.chain(xrange(len(S)),
                                 reversed(xrange(len(S)))):
            if S[i] == C:
                prev = i
            result[i] = min(result[i], abs(i-prev))
        return result

