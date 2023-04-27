# Time:  O(nlogn)
# Space: O(n)

# sort, line sweep
class Solution(object):
    def findMaximalUncoveredRanges(self, n, ranges):
        """
        :type n: int
        :type ranges: List[List[int]]
        :rtype: List[List[int]]
        """
        ranges.sort()
        covered = [[-1, -1]]
        for left, right in ranges:
            if covered[-1][1] < left:
                covered.append([left, right])
                continue
            covered[-1][1] = max(covered[-1][1], right)    
        covered.append([n, n])        
        return [[covered[i-1][1]+1, covered[i][0]-1] for i in xrange(1, len(covered)) if covered[i-1][1]+1 <= covered[i][0]-1]
