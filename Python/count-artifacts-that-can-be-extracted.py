# Time:  O(a + d), a is the number of grids covered by artifacts, d is the size of dig
# Space: O(d)

# hash table
class Solution(object):
    def digArtifacts(self, n, artifacts, dig):
        """
        :type n: int
        :type artifacts: List[List[int]]
        :type dig: List[List[int]]
        :rtype: int
        """
        lookup = set(map(tuple, dig))
        return sum(all((i, j) in lookup for i in xrange(r1, r2+1) for j in xrange(c1, c2+1)) for r1, c1, r2, c2 in artifacts)
    

# Time:  O(a + d), a is the number of grids covered by artifacts, d is the size of dig
# Space: O(a)
# hash table
class Solution2(object):
    def digArtifacts(self, n, artifacts, dig):
        """
        :type n: int
        :type artifacts: List[List[int]]
        :type dig: List[List[int]]
        :rtype: int
        """
        lookup = {(i, j):idx for idx, (r1, c1, r2, c2) in enumerate(artifacts) for i in xrange(r1, r2+1) for j in xrange(c1, c2+1)}
        cnt = [(r2-r1+1)*(c2-c1+1) for r1, c1, r2, c2 in artifacts]
        result = 0
        for i, j in dig:
            if (i, j) not in lookup:
                continue
            cnt[lookup[i, j]] -= 1
            if not cnt[lookup[i, j]]:
                result += 1
        return result
