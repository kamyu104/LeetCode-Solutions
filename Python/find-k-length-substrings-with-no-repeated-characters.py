# Time:  O(n)
# Space: O(k)

class Solution(object):
    def numKLenSubstrNoRepeats(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: int
        """
        result, i = 0, 0
        lookup = set()
        for j in xrange(len(S)):
            while S[j] in lookup:
                lookup.remove(S[i])
                i += 1
            lookup.add(S[j])
            result += j-i+1 >= K
        return result
