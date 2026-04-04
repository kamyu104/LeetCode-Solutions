# Time:  O(m * n)
# Space: O(k * n)

# sliding window, greedy, difference array
class Solution(object):
    def minOperations(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        c, target, mn = 0, 0, float("-inf")
        found = False
        lookup = [[0]*len(grid[0]) for _ in xrange(k)]
        cnt = [0]*len(grid[0])
        for i in xrange(len(grid)):
            total = 0
            for j in xrange(len(grid[0])):
                total += cnt[j]
                diff = -(grid[i][j]+total)  # grid[i][j] + total + diff = target
                if i+k-1 < len(grid) and j+k-1 < len(grid[0]):
                    lookup[i%k][j] = diff
                    cnt[j] += diff
                    total += diff
                    c += diff
                    if i%k == 0 and j%k == 0:  # target + diff >= 0, target >= -diff
                        mn = max(mn, -diff)
                    elif not diff >= 0:  # diff >= 0
                        return -1
                else:
                    if (i//k+1)*k <= len(grid) and (j//k+1)*k <= len(grid[0]):
                        if diff:
                            return -1
                    else:
                        if not found:
                            found = True
                            target = -diff
                        elif target != -diff:
                            return -1
                if j-k+1 >= 0:
                    total -= cnt[j-k+1]
            if i-k+1 >= 0:
                for j in xrange(len(grid[0])):
                    cnt[j] -= lookup[(i-k+1)%k][j]
                    lookup[(i-k+1)%k][j] = 0
        if not found:
            target = mn
        elif target < mn:
            return -1
        return c+target*((len(grid)//k)*(len(grid[0])//k))
