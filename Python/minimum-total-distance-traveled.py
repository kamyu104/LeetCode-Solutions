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
        dp = [float("inf")]*(len(robot)+1)  # dp[j] at i: min of factory[:i+1] and robot[:j]
        dp[0] = 0
        for i in xrange(len(factory)):
            prefix = 0
            dq = collections.deque([(dp[0]-prefix, 0)])  # pattern of min in the sliding window with size (limit+1)
            for j in xrange(1, len(robot)+1):
                prefix += abs(robot[j-1]-factory[i][0])
                if j-dq[0][1] == factory[i][1]+1:
                    dq.popleft()
                while dq and dq[-1][0] >= dp[j]-prefix:
                    dq.pop()
                dq.append((dp[j]-prefix, j))
                dp[j] = dq[0][0]+prefix
        return dp[-1]


# Time:  O(mlogm + nlogn + m * n * l), l is the max limit
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
        dp = [float("inf")]*(len(robot)+1)  # dp[j] at i: min of factory[:i+1] and robot[:j]
        dp[0] = 0
        for i in xrange(len(factory)):
            for j in reversed(xrange(1, len(robot)+1)):
                curr = 0
                for k in xrange(min(factory[i][1], j)+1):
                    dp[j] = min(dp[j], dp[j-k]+curr)
                    if (j-1)-k >= 0:
                        curr += abs(robot[(j-1)-k]-factory[i][0])
        return dp[-1]
