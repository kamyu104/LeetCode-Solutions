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
        dp = [float("inf")]*len(prices)
        dp[0] = prices[0]
        dq = collections.deque()
        j = 1
        for i in xrange(1, len(prices)):
            while dq and dp[dq[-1]-1]+prices[dq[-1]] >= dp[i-1]+prices[i]:
                dq.pop()
            dq.append(i)
            if i == 1:
                dp[1] = prices[0]
                continue
            while j+(j+1) < i:
                j += 1
                if dq[0] < j:
                    assert(len(dq) != 0)
                    dq.popleft()
            dp[i] = dp[dq[0]-1]+prices[dq[0]]
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
        dp = [float("inf")]*len(prices)
        dp[0] = prices[0]
        sl = SortedList()
        j = 1
        for i in xrange(1, len(prices)):
            sl.add((dp[i-1]+prices[i], i))
            if i == 1:
                dp[1] = prices[0]
                continue
            while j+(j+1) < i:
                sl.remove(((dp[j-1]+prices[j], j)))
                j += 1
            dp[i] = sl[0][0]
        return dp[-1]


# Time:  O(n^2)
# Space: O(n)
# dp
class Solution3(object):
    def minimumCoins(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp = [float("inf")]*len(prices)
        dp[0] = prices[0]
        for i in xrange(1, len(prices)):
            if i == 1:
                dp[1] = prices[0]
                continue
            for j in xrange(max(i//2, 1), i+1):
                dp[i] = min(dp[i], dp[j-1]+prices[j])
        return dp[-1]
