# Time:  O(n * m * l + n^2 * m), n is favoriteCompanies.length
#                              , m is the max of favoriteCompanies[i].length
#                              , l is the max of favoriteCompanies[i][j].length
# Space: O(n * m * l)

class Solution(object):
    def peopleIndexes(self, favoriteCompanies):
        """
        :type favoriteCompanies: List[List[str]]
        :rtype: List[int]
        """
        lookup, comps = {}, []
        for cs in favoriteCompanies:
            comps.append(set())
            for c in cs:
                if c not in lookup:
                    lookup[c] = len(lookup)
                comps[-1].add(lookup[c])
        return [i for i, c1 in enumerate(comps)
                if not any(i != j and len(c1) < len(c2) and c1 < c2
                           for j, c2 in enumerate(comps))]
    


# Time:  O(n * m * l + n^2 * m * log*(n)), n is favoriteCompanies.length
#                                        , m is the max of favoriteCompanies[i].length
#                                        , l is the max of favoriteCompanies[i][j].length
# Space: O(n * m * l)
class UnionFind(object):
    def __init__(self, data):
        self.data = [set(d) for d in data]
        self.set = range(len(data))

    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root == y_root:
            return
        if len(self.data[x_root]) > len(self.data[y_root]) and \
           self.data[x_root] > self.data[y_root]:
            self.set[y_root] = x_root
        elif len(self.data[x_root]) < len(self.data[y_root]) and \
           self.data[x_root] < self.data[y_root]:
            self.set[x_root] = y_root


class Solution2(object):
    def peopleIndexes(self, favoriteCompanies):
        """
        :type favoriteCompanies: List[List[str]]
        :rtype: List[int]
        """
        lookup, comps = {}, []
        for cs in favoriteCompanies:
            comps.append(set())
            for c in cs:
                if c not in lookup:
                    lookup[c] = len(lookup)
                comps[-1].add(lookup[c])
        union_find = UnionFind(comps)
        for i in xrange(len(comps)):
            for j in xrange(len(comps)):
                if j == i:
                    continue
                union_find.union_set(i, j)
        return [x for i, x in enumerate(union_find.set) if x == i]
