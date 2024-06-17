# Time:  O(nlogn)
# Space: O(1)

import collections


# sort, dp, two pointers, sliding window, deque
class Solution(object):
    def maximumTotalDamage(self, power):
        """
        :type power: List[int]
        :rtype: int
        """
        DIST = 2
        power.sort()
        dp = collections.deque()
        mx = 0
        for x in power:
            if dp and dp[-1][0] == x:
                dp[-1][1] += x
                continue
            while dp and dp[0][0]+DIST < x:
                mx = max(mx, dp.popleft()[1])
            dp.append([x, mx+x])
        return max(x for _, x in dp)
