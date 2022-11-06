# Time:  O(mlogm + nlogn + m * n)
# Space: O(m * n)

import collections


# dp, mono deque
class Solution(object):
    def minimumTotalDistance(self, robot, factory):
        """
        :type robot: List[int]
        :type factory: List[List[int]]
        :rtype: int
        """
        robot.sort(), factory.sort()
        dp = [[float("inf")]*(len(factory)+1) for _ in xrange(len(robot))]  # dp[i][j]: min of robot[:i+1] and factory[:j]
        for j in xrange(len(factory)):
            prefix = 0
            dq = collections.deque([(0, -1)])
            for i in xrange(len(robot)):
                prefix += abs(robot[i]-factory[j][0])
                if i-dq[-1][1] == factory[j][1]+1:
                    dq.pop()
                while dq and dq[0][0] >= dp[i][j]-prefix:
                    dq.popleft()
                dq.appendleft((dp[i][j]-prefix, i))
                dp[i][j+1] = dq[-1][0]+prefix
        return dp[-1][-1]


