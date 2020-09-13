# Time:  O(n)
# Space: O(n)

class Solution(object):
    def isTransformable(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        idx = [[] for _ in xrange(10)]
        for i in reversed(xrange(len(s))):
            idx[int(s[i])].append(i)
        for c in t:
            d = int(c)
            if not idx[d]:
                return False
            for k in xrange(d):  # a char can be moved left to the current position if it meets no smaller one
                if idx[k] and idx[k][-1] < idx[d][-1]:
                    return False
            idx[d].pop()
        return True
