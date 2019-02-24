# Time:  O(t + n)
# Space: O(n)

class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        degrees = [0]*N
        for i, j in trust:
            degrees[i-1] -= 1
            degrees[j-1] += 1
        for i in xrange(len(degrees)):
            if degrees[i] == N-1:
                return i+1
        return -1
