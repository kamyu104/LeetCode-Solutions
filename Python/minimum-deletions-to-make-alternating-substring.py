# Time:  O((n + q) * logn)
# Space: O(n)

# fenwick tree
class BIT(object):  # 0-indexed.
    def __init__(self, n):
        self.__bit = [0]*(n+1)  # Extra one for dummy node.

    def add(self, i, val):
        i += 1  # Extra one for dummy node.
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1  # Extra one for dummy node.
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret
        

class Solution(object):
    def minDeletions(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        s = list(s)
        bit = BIT(len(s)-1)
        for i in xrange(len(s)-1):
            if s[i] == s[i+1]:
                bit.add(i, 1)
        result = []
        for q in queries:
            if len(q) == 3:
                result.append(bit.query(q[2]-1)-bit.query(q[1]-1))
                continue
            i = q[1]
            s[i] = u'B' if s[i] == u'A' else u'A'
            if i-1 >= 0:
                bit.add(i-1, 1 if s[i-1] == s[i] else -1)
            if i+1 < len(s):
                bit.add(i, 1 if s[i] == s[i+1] else -1)            
        return result
