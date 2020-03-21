# Time:  O(n^2)
# Space: O(n)

# [observation]
# 1. we can never take two adjacent slices
# 2. if we want some set of N / 3 non-adjacent slices, there is always a way to take
#
# [proof]
# - for N = 3, it is obviously true.
# - for N' = N + 3,
#   - because it's impossible to have only one unwanted slices between all wanted slices.
#     if it's true, there will be 3N'/2 unwanted slices rather than 2N' unwanted ones, -><-
#   - so we can always find a sequence of two unwanted slices with one wanted slice
#     to take firstly, then we can find a way to take the remaining N ones by induction, QED

# better optimized space
class Solution(object):
    def maxSizeSlices(self, slices):
        """
        :type slices: List[int]
        :rtype: int
        """
        def maxSizeSlicesLinear(slices, start, end):
            dp = [[0]*(len(slices)//3+1) for _ in xrange(2)]
            for i in xrange(start, end):
                for j in reversed(xrange(1, min(((i-start+1)-1)//2+1, len(slices)//3)+1)):
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-2)%2][j-1] + slices[i])
            return dp[(end-1)%2][len(slices)//3]
        
        return max(maxSizeSlicesLinear(slices, 0, len(slices)-1),
                   maxSizeSlicesLinear(slices, 1, len(slices)))


# Time:  O(n^2)
# Space: O(n)
class Solution2(object):
    def maxSizeSlices(self, slices):
        """
        :type slices: List[int]
        :rtype: int
        """
        def maxSizeSlicesLinear(slices, start, end):
            dp = [[0]*(len(slices)//3+1) for _ in xrange(3)]
            for i in xrange(start, end):
                for j in xrange(1, min(((i-start+1)-1)//2+1, len(slices)//3)+1):
                    dp[i%3][j] = max(dp[(i-1)%3][j], dp[(i-2)%3][j-1] + slices[i])
            return dp[(end-1)%3][len(slices)//3]
        
        return max(maxSizeSlicesLinear(slices, 0, len(slices)-1),
                   maxSizeSlicesLinear(slices, 1, len(slices)))
