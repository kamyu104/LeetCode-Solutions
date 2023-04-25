# Time:  O(n^2)
# Space: O(1)

# constructive algorithms
class Solution(object):
    def colorRed(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        result = [[1, 1]]
        for i in xrange(2, n+1):
            if i%2 == n%2:
                result.extend([i, j] for j in xrange((1 if i%4 == n%4 else 3), 2*i, 2))
            else:
                result.append([i, (2 if i%4 == (n-1)%4 else 1)])
        return result
