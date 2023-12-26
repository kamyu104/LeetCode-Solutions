# Time:  O(n)
# Space: O(n)

import collections


# dp, mono deque
class Solution(object):
    def minimumCoins(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [float("inf")]*(len(prices)+1)
        dp[0] = 0
        dq = collections.deque()
        j = 0
        for i in xrange(len(prices)):
            while dq and dp[dq[-1]]+prices[dq[-1]] >= dp[i]+prices[i]:
                dq.pop()
            dq.append(i)
            while j+(j+1) < i:
                assert(len(dq) != 0)
                if dq[0] == j:
                    dq.popleft()
                j += 1
            dp[i+1] = dp[dq[0]]+prices[dq[0]]
        return dp[-1]


# Time:  O(nlogn)
# Space: O(n)
# dp, sorted list
from sortedcontainers import SortedList


class Solution2(object):
    def minimumCoins(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [float("inf")]*(len(prices)+1)
        dp[0] = 0
        sl = SortedList()
        j = 0
        for i in xrange(len(prices)):
            sl.add((dp[i]+prices[i], i))
            while j+(j+1) < i:
                sl.remove(((dp[j]+prices[j], j)))
                j += 1
            dp[i+1] = sl[0][0]
        return dp[-1]
