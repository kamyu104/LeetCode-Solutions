# Time:  O(m * 2^n)
# Space: O(2^n)

# bitmasks, constructive algorithms, greedy, submask enumeration
class Solution(object):
    def goodSubsetofBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        lookup = {}
        for i in xrange(len(grid)):
            mask = reduce(lambda mask, j: mask|(grid[i][j]<<j), xrange(len(grid[0])), 0)
            if not mask:
                return [i]
            mask2 = ((1<<len(grid[0]))-1)^mask
            submask = mask2  # submask enumeration
            while submask > 0:
                if submask in lookup:
                    return [lookup[submask], i]
                submask = (submask-1)&mask2                
            lookup[mask] = i
        return []


# Time:  O(m * 2^n)
# Space: O(2^n)
# bitmasks, constructive algorithms, greedy
class Solution2(object):
    def goodSubsetofBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        lookup = {}
        for i in xrange(len(grid)):
            mask = reduce(lambda mask, j: mask|(grid[i][j]<<j), xrange(len(grid[0])), 0)
            if not mask:
                return [i]
            for mask2 in xrange(1, 1<<len(grid[0])):
                if mask&mask2:
                    continue
                if mask2 in lookup:
                    return [lookup[mask2], i]
            lookup[mask] = i
        return []
