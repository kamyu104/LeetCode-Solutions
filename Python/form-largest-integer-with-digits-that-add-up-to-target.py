# Time:  O(t)
# Space: O(t)

class Solution(object):
    def largestNumber(self, cost, target):
        """
        :type cost: List[int]
        :type target: int
        :rtype: str
        """
        dp = [0] + [-1]*(target)
        for t in xrange(1, target+1):
            for i, c in enumerate(cost):
                if t-c < 0 or dp[t-c] < 0:
                    continue
                dp[t] = max(dp[t], dp[t-c]+1)
        if dp[target] < 0:
            return "0"
        result = []
        for i in reversed(xrange(1, 9)):
            while target >= cost[i] and dp[target] == dp[target-cost[i]]+1:
                target -= cost[i]
                result.append(i)
        return "".join(map(str, result))


# Time:  O(t^2)
# Space: O(t^2)
class Solution(object):
    def largestNumber(self, cost, target):
        """
        :type cost: List[int]
        :type target: int
        :rtype: str
        """
        dp = [0] + [-1]*(target)
        for t in xrange(1, target+1):
            for i, c in enumerate(cost):
                if t-c < 0:
                    continue
                dp[t] = max(dp[t], dp[t-c]*10 + i+1)
        return str(max(dp[t], 0))
