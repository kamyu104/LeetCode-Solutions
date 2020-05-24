# Time:  O(t)
# Space: O(t)

class Solution(object):
    def largestNumber(self, cost, target):
        """
        :type cost: List[int]
        :type target: int
        :rtype: str
        """
        dp = [0]
        for t in xrange(1, target+1):
            dp.append(-1)
            for i, c in enumerate(cost):
                if t-c < 0 or dp[t-c] < 0:
                    continue
                dp[t] = max(dp[t], dp[t-c]+1)
        if dp[target] < 0:
            return "0"
        result = []
        for i in reversed(xrange(9)):
            while target >= cost[i] and dp[target] == dp[target-cost[i]]+1:
                target -= cost[i]
                result.append(i+1)
        return "".join(map(str, result))


# Time:  O(t)
# Space: O(t)
class Solution2(object):
    def largestNumber(self, cost, target):
        """
        :type cost: List[int]
        :type target: int
        :rtype: str
        """
        def key(bag):
            return sum(bag), bag
        
        dp = [[0]*9]
        for t in xrange(1, target+1):
            dp.append([])
            for d, c in enumerate(cost):
                if t < c or not dp[t-c]:
                    continue
                curr = dp[t-c][:]
                curr[~d] += 1
                if key(curr) > key(dp[t]):
                    dp[-1] = curr        
        if not dp[-1]:
            return "0"
        return "".join(str(9-i)*c for i, c in enumerate(dp[-1]))


# Time:  O(t^2)
# Space: O(t^2)
class Solution3(object):
    def largestNumber(self, cost, target):
        """
        :type cost: List[int]
        :type target: int
        :rtype: str
        """
        dp = [0]
        for t in xrange(1, target+1):
            dp.append(-1)
            for i, c in enumerate(cost):
                if t-c < 0:
                    continue
                dp[t] = max(dp[t], dp[t-c]*10 + i+1)
        return str(max(dp[t], 0))
