# Time:  O(m * n)
# Space: O(1)

# array
class Solution(object):
    def canPartitionGrid(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        def check1():
            curr = 0
            for i in xrange(len(grid)):
                curr += sum(grid[i])
                if curr == total:
                    return True
                elif curr > total:
                    break
            return False
    
        def check2():
            curr = 0
            for j in xrange(len(grid[0])):
                curr += sum(grid[i][j] for i in xrange(len(grid)))
                if curr == total:
                    return True
                elif curr > total:
                    break
            return False
    
        total = sum(sum(row) for row in grid)
        if total%2:
            return False
        total //= 2
        return check1() or check2()
