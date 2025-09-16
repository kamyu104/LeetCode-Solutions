# Time:  O(n^2)
# Space: O(1)

# constructive algorithms
class Solution(object):
    def generateSchedule(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        result = []
        if n <= 4:
            return result
        l = 1
        if n%2 == 0:
            for i in xrange(0, n, 2):
                result.append([i, i+l])
            for i in xrange(0, n, 2):
                result.append([i+l, i])
            for i in xrange(1, n, 2):
                result.append([i, (i+l)%n])
            for i in xrange(1, n, 2):
                result.append([(i+l)%n, i])
        else:
            for i in xrange(0, 2*n, 2):
                result.append([i%n, (i+l)%n])
            for i in xrange(0, 2*n, 2):
                result.append([(i+l)%n, i%n])
        for l in xrange(2, (n+1)//2):
            j = result[-1][0]+1
            for i in xrange(j, j+n):
                result.append([i%n, (i+l)%n])
            j = result[-1][1]-1
            for i in xrange(j, j+n):
                result.append([(i+l)%n, i%n])
        if n%2 == 0:
            l = n//2
            j = result[-1][0]-1
            for i in xrange(j, j+n):
                result.append([i%n, (i+l)%n])
        return result
