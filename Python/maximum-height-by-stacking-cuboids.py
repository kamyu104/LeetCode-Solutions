# Time:  O(n^2)
# Space: O(n)
    
class Solution(object):
    def maxHeight(self, cuboids):
        """
        :type cuboids: List[List[int]]
        :rtype: int
        """
        for cuboid in cuboids:
            cuboid.sort()
        cuboids.append([0, 0, 0])
        cuboids.sort()
        dp = [0]*len(cuboids)
        for i in xrange(1, len(cuboids)):
            for j in xrange(i):
                if all(cuboids[j][k] <= cuboids[i][k] for k in xrange(3)):
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2])
        return max(dp)
