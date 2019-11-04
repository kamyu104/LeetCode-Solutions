# Time:  O(nlog*n) ~= O(n), n is the length of S
# Space: O(n)

class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return False
        self.set[max(x_root, y_root)] = min(x_root, y_root)
        return True
    

class Solution(object):
    def smallestEquivalentString(self, A, B, S):
        """
        :type A: str
        :type B: str
        :type S: str
        :rtype: str
        """
        union_find = UnionFind(26)
        for i in xrange(len(A)):
            union_find.union_set(ord(A[i])-ord('a'), ord(B[i])-ord('a'))
        result = []
        for i in xrange(len(S)):
            parent = union_find.find_set(ord(S[i])-ord('a'))
            result.append(chr(parent+ord('a')))
        return "".join(result)
