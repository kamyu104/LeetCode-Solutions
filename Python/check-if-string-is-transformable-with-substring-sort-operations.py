# Time:  O(n)
# Space: O(n)

class Solution(object):
    def isTransformable(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        idxs = [[] for _ in xrange(10)]
        for i in reversed(xrange(len(s))):
            idxs[int(s[i])].append(i)
        for c in t:
            d = int(c)
            if not idxs[d]:
                return False
            for k in xrange(d):  # a char can be moved left to the current position if it meets no smaller one
                if idxs[k] and idxs[k][-1] < idxs[d][-1]:
                    return False
            idxs[d].pop()
        return True
