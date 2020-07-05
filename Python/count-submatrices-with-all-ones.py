# Time:  O(m * n)
# Space: O(n)

class Solution(object):
    def numSubmat(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        def count(heights):
            dp, stk = [0]*len(heights), []
            for i in xrange(len(heights)):
                while stk and heights[stk[-1]] >= heights[i]:
                    stk.pop()
                dp[i] = dp[stk[-1]] + heights[i]*(i-stk[-1]) if stk else heights[i]*(i-(-1))
                stk.append(i)
            return sum(dp)

        result = 0
        heights = [0]*len(mat[0])
        for i in xrange(len(mat)):
            for j in xrange(len(mat[0])):
                heights[j] = heights[j]+1 if mat[i][j] == 1 else 0
            result += count(heights)
        return result
