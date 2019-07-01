# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def minHeightShelves(self, books, shelf_width):
        """
        :type books: List[List[int]]
        :type shelf_width: int
        :rtype: int
        """
        dp = [float("inf") for _ in xrange(len(books)+1)]
        dp[0] = 0
        for i in xrange(1, len(books)+1):
            max_width = shelf_width
            max_height = 0
            for j in reversed(xrange(i)):
                if max_width-books[j][0] < 0:
                    break
                max_width -= books[j][0]
                max_height = max(max_height, books[j][1])
                dp[i] = min(dp[i], dp[j]+max_height)
        return dp[len(books)]
