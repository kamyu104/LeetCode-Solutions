# Time:  O(n^2 * (l^2 + 2^n))
# Space: O(n^2)

class Solution(object):
    def shortestSuperstring(self, A):
        """
        :type A: List[str]
        :rtype: str
        """
        n = len(A)
        overlaps = [[0]*n for _ in xrange(n)]
        for i, x in enumerate(A):
            for j, y in enumerate(A):
                for l in reversed(xrange(min(len(x), len(y)))):
                    if y[:l].startswith(x[len(x)-l:]):
                        overlaps[i][j] = l
                        break

        dp = [[0]*n for _ in xrange(1<<n)]
        prev = [[None]*n for _ in xrange(1<<n)]
        for mask in xrange(1, 1<<n):
            for bit in xrange(n):
                if ((mask>>bit) & 1) == 0:
                    continue
                prev_mask = mask^(1<<bit)
                for i in xrange(n):
                    if ((prev_mask>>i) & 1) == 0:
                        continue
                    value = dp[prev_mask][i] + overlaps[i][bit]
                    if value > dp[mask][bit]:
                        dp[mask][bit] = value
                        prev[mask][bit] = i
        
        bit = max(xrange(n), key = dp[-1].__getitem__)
        words = []
        mask = (1<<n)-1
        while bit is not None:
            words.append(bit)
            mask, bit = mask^(1<<bit), prev[mask][bit]
        words.reverse()
        lookup = set(words)
        words.extend([i for i in xrange(n) if i not in lookup])

        result = [A[words[0]]]
        for i in xrange(1, len(words)):
            overlap = overlaps[words[i-1]][words[i]]
            result.append(A[words[i]][overlap:])
        return "".join(result)
