# Time:  O(n!)
# Space: O(n)

class Solution(object):
    def constructDistancedSequence(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def backtracking(n, i, s, lookup):
            if i == len(s):
                return True
            if s[i]:
                return backtracking(n, i+1, s, lookup)
            for x in reversed(xrange(1, n+1)):
                j = i if x == 1 else i+x
                if lookup[x] or j >= len(s) or s[j]:
                    continue
                s[i], s[j], lookup[x] = x, x, True
                if backtracking(n, i+1, s, lookup):
                    return True
                s[i], s[j], lookup[x] = 0, 0, False
            return False

        s, lookup = [0]*(2*n-1), [False]*(n+1)
        backtracking(n, 0, s, lookup)
        return s
