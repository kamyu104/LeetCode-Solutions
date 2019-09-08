# Time:  O(n)
# Space: O(n)

class Solution(object):
    def shortestDistanceColor(self, colors, queries):
        """
        :type colors: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        dp = [[float("inf") for _ in xrange(len(colors))] for _ in xrange(3)]
        dp[colors[0]-1][0] = 0
        for i in xrange(1, len(colors)):
            for color in xrange(3):
                dp[color][i] = dp[color][i-1]+1
            dp[colors[i]-1][i] = 0

        dp[colors[len(colors)-1]-1][len(colors)-1] = 0
        for i in reversed(xrange(len(colors)-1)):
            for color in xrange(3):
                if abs(dp[color][i+1]-1) < dp[color][i]:
                    dp[color][i] = dp[color][i+1]-1
            dp[colors[i]-1][i] = 0
         
        return [abs(dp[color-1][i]) if abs(dp[color-1][i]) != float("inf") else -1 \
                    for i, color in queries]

# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def shortestDistanceColor(self, colors, queries):
        """
        :type colors: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        
        left = [[float("inf") for _ in xrange(len(colors))] for _ in xrange(3)]
        left[colors[0]-1][0] = 0
        for i in xrange(1, len(colors)):
            for color in xrange(3):
                left[color][i] = left[color][i-1]+1
            left[colors[i]-1][i] = 0

        right = [[float("inf") for _ in xrange(len(colors))] for _ in xrange(3)]
        right[colors[len(colors)-1]-1][len(colors)-1] = 0
        for i in reversed(xrange(len(colors)-1)):
            for color in xrange(3):
                right[color][i] = right[color][i+1]+1
            right[colors[i]-1][i] = 0
         
        return [min(left[color-1][i], right[color-1][i]) \
                if min(left[color-1][i], right[color-1][i]) != float("inf") \
                else -1 \
                    for i, color in queries]
  
