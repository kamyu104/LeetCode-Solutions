# Time:  O(p*l * log(p*l)), p is the production of all number of synonyms
#                         , l is the length of a word
# Space: O(p*l)

import collections
import itertools


class UnionFind(object):
    def __init__(self, n):
        self.set = range(n)
        self.count = n

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
    def generateSentences(self, synonyms, text):
        """
        :type synonyms: List[List[str]]
        :type text: str
        :rtype: List[str]
        """
        def assign_id(x, lookup, inv_lookup):
            if x in lookup:
                return
            lookup[x] = len(lookup)
            inv_lookup[lookup[x]] = x
        
        lookup, inv_lookup = {}, {}
        for u, v in synonyms:
            assign_id(u, lookup, inv_lookup), assign_id(v, lookup, inv_lookup)
        union_find = UnionFind(len(lookup))
        for u, v in synonyms:
            union_find.union_set(lookup[u], lookup[v])
        groups = collections.defaultdict(list)
        for i in xrange(len(union_find.set)):
            groups[union_find.find_set(i)].append(i)
        result = []
        for w in text.split(' '):
            if w not in lookup:
                result.append([w])
                continue
            result.append(sorted(map(lambda x: inv_lookup[x], 
                                 groups[union_find.find_set(lookup[w])])))
        return [" ".join(sentense) for sentense in itertools.product(*result)]
