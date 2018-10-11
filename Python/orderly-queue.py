# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def orderlyQueue(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        if K == 1:
            return min(S[i:] + S[:i] for i in xrange(len(S)))
        return "".join(sorted(S))

