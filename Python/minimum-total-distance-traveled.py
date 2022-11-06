# Time:  O(mlogm + nlogn + m * n)
# Space: O(n)

import collections


# sort, dp, prefix sum, mono deque
class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        """
        :type robot: List[int]
        :type factory: List[List[int]]
        :rtype: int
        """
        robot.sort(), factory.sort()
        dp = [float("inf")]*(len(robot))  # dp[j]: min of factory[:i] and robot[:j+1]
        for i in xrange(len(factory)):
            prefix = 0
            dq = collections.deque([(0, -1)])
            for j in xrange(len(robot)):
                prefix += abs(robot[j]-factory[i][0])
                if j-dq[-1][1] == factory[i][1]+1:
                    dq.pop()
                while dq and dq[0][0] >= dp[j]-prefix:
                    dq.popleft()
                dq.appendleft((dp[j]-prefix, j))
                dp[j] = dq[-1][0]+prefix
        return dp[-1]


# Time:  O(mlogm + nlogn + m * n * k)
# Space: O(n)
import collections


# sort, dp
class Solution2(object):
    def minimumTotalDistance(self, robot, factory):
        """
        :type robot: List[int]
        :type factory: List[List[int]]
        :rtype: int
        """
        robot.sort(), factory.sort()
        dp = [float("inf")]*(len(robot)+1)  # dp[j]: min of factory[:i] and robot[:j]
        dp[0] = 0
        for i in xrange(len(factory)):
            new_dp = [float("inf")]*(len(robot)+1)
            new_dp[0] = 0
            for j in xrange(1, len(robot)+1):
                prefix = 0
                for k in xrange(min(factory[i][1], j)+1):
                    new_dp[j] = min(new_dp[j], dp[j-k]+prefix)
                    if (j-1)-k >= 0:
                        prefix += abs(robot[(j-1)-k]-factory[i][0])
            dp = new_dp
        return dp[-1]
