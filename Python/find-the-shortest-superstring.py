# Time:  O(n^2 * (l^2 + 2^n))
# Space: O(n^2)

class Solution(object):
    def shortestSuperstring(self, A):
        """
        :type A: List[str]
        :rtype: str
        """
        N = len(A)
        overlaps = [[0]*N for _ in xrange(N)]
        for i, x in enumerate(A):
            for j, y in enumerate(A):
                if i == j:
                    continue
                for l in reversed(xrange(min(len(x), len(y)))):
                    if x.endswith(y[:l]):
                        overlaps[i][j] = l
                        break

        dp = [[0]*N for _ in xrange(1<<N)]
        prev = [[None]*N for _ in xrange(1<<N)]
        for mask in xrange(1, 1<<N):
            for bit in xrange(N):
                if (mask>>bit) & 1 == 0:
                    continue
                prev_mask = mask^(1<<bit)
                for i in xrange(N):
                    if (prev_mask>>i) & 1 == 0:
                        continue
                    value = dp[prev_mask][i] + overlaps[i][bit]
                    if value > dp[mask][bit]:
                        dp[mask][bit] = value
                        prev[mask][bit] = i
        
        i = max(xrange(N), key = dp[-1].__getitem__)
        words = []
        mask = (1<<N)-1
        while i is not None:
            words.append(i)
            mask, i = mask^(1<<i), prev[mask][i]
        words.reverse()
        lookup = set(words)
        words.extend([i for i in xrange(N) if i not in lookup])

        result = [A[words[0]]]
        for i in xrange(1, len(words)):
            overlap = overlaps[words[i-1]][words[i]]
            result.append(A[words[i]][overlap:])
        return "".join(result)
