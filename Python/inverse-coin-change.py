# Time:  O(n^2)
# Space: O(1)

# dp
class Solution(object):
    def findCoins(self, numWays):
        """
        :type numWays: List[int]
        :rtype: List[int]
        """
        result = []
        for i in xrange(1, len(numWays)+1):
            if numWays[i-1] == 1:
                result.append(i)
                for j in reversed(xrange(i, len(numWays)+1)):
                    numWays[j-1] -= numWays[(j-i)-1] if (j-i)-1 >= 0 else 1
            if numWays[i-1]:
                return []
        return result


# Time:  O(n^2)
# Space: O(n)
# dp
class Solution2(object):
    def findCoins(self, numWays):
        """
        :type numWays: List[int]
        :rtype: List[int]
        """
        result = []
        dp = [0]*(len(numWays)+1)
        dp[0] = 1
        for i in xrange(1, len(numWays)+1):
            if numWays[i-1]-dp[i] == 1:
                result.append(i)
                for j in xrange(i, len(numWays)+1):
                    dp[j] += dp[j-i]
            if numWays[i-1]-dp[i]:
                return []
        return result
