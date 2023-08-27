# Time:  O(nlogk)
# Space: O(nlogk)

# binary lifting
class Solution(object):
    def getMaxFunctionValue(self, receiver, k):
        """
        :type receiver: List[int]
        :type k: int
        :rtype: int
        """
        l = (k+1).bit_length()
        P = [receiver[:] for _ in xrange(l)]
        S = [range(len(receiver)) for _ in xrange(l)]
        for i in xrange(1, len(P)):
            for u in xrange(len(receiver)):
                P[i][u] = P[i-1][P[i-1][u]]
                S[i][u] = S[i-1][u]+S[i-1][P[i-1][u]]
        result = 0
        for u in xrange(len(receiver)):
            curr = 0
            for i in xrange(l):
                if (k+1)&(1<<i):
                    curr += S[i][u]
                    u = P[i][u]
            result = max(result, curr)
        return result
