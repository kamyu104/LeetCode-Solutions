# Time:  O(n + p)
# Space: O(p)

import itertools


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
        self.set[min(x_root, y_root)] = max(x_root, y_root)
        return True


class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2): return False

        lookup = {}
        union_find = UnionFind(2 * len(pairs))
        for pair in pairs:
            for p in pair:
                if p not in lookup:
                    lookup[p] = len(lookup)
            union_find.union_set(lookup[pair[0]], lookup[pair[1]])

        return all(w1 == w2 or
                   w1 in lookup and w2 in lookup and
                   union_find.find_set(lookup[w1]) == union_find.find_set(lookup[w2])
                   for w1, w2 in itertools.izip(words1, words2))

