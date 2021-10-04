# Time:  O(n)
# Space: O(1)

class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        MAX_V = 6
        MIN_V = 1
        total = sum(rolls)
        missing = mean*(n+len(rolls))-total
        if missing < MIN_V*n or missing > MAX_V*n:
            return []
        q, r = divmod(missing, n)
        return [q+int(i < r) for i in xrange(n)]


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        MAX_V = 6
        MIN_V = 1
        total = sum(rolls)
        missing = mean*(n+len(rolls))-total
        if missing < MIN_V*n or missing > MAX_V*n:
            return []
        q, r = divmod(missing-MIN_V*n, (MAX_V-MIN_V))
        return [MAX_V if i < q else MIN_V+r if i == q else MIN_V  for i in xrange(n)]
