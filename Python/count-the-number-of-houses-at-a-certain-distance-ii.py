# Time:  O(n)
# Space: O(n)

# math, difference array
class Solution(object):
    def countOfPairs(self, n, x, y):
        """
        :type n: int
        :type x: int
        :type y: int
        :rtype: List[int]
        """
        x, y = x-1, y-1
        if x > y:
            x, y = y, x
        diff = [0]*n
        for i in xrange(n):
            diff[0] += 1+1                                         # i -> two directions begin
            diff[min(abs(i-x), abs(i-y)+1)] += 1                   # i -> x -> y, fork one direction at y
            diff[min(abs(i-y), abs(i-x)+1)] += 1                   # i -> y -> x, fork one direction at x
            diff[min(abs(i-0), abs(i-y)+1+abs(x-0))] -= 1          # i -> 0, one direction ends
            diff[min(abs(i-(n-1)), abs(i-x)+1+abs(y-(n-1)))] -= 1  # i -> n-1, one direction ends
            diff[max(x-i, 0)+max(i-y, 0)+((y-x)+0)//2] -= 1        # i -> x -> ((y-x)+0)//2 <- x, one direction ends
            diff[max(x-i, 0)+max(i-y, 0)+((y-x)+1)//2] -= 1        # i -> y -> ((y-x)+1)//2 <- y, one direction ends
        for i in xrange(n-1):
            diff[i+1] += diff[i]
        return diff
