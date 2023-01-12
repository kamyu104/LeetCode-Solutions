# Time:  O(n), n = maxLength
# Space: O(w), w = max(oneGroup, zeroGroup)+1

# dp
class Solution(object):
    def goodBinaryStrings(self, minLength, maxLength, oneGroup, zeroGroup):
        """
        :type minLength: int
        :type maxLength: int
        :type oneGroup: int
        :type zeroGroup: int
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        w = max(oneGroup, zeroGroup)+1
        dp = [0]*w
        for i in xrange(maxLength+1):
            dp[i%w] = 1 if i == 0 else 0
            if i-oneGroup >= 0:
                dp[i%w] = (dp[i%w]+dp[(i-oneGroup)%w])%MOD
            if i-zeroGroup >= 0:
                dp[i%w] = (dp[i%w]+dp[(i-zeroGroup)%w])%MOD
            if i >= minLength:
                result = (result+dp[i%w])%MOD
        return result


# Time:  O(n), n = maxLength
# Space: O(n)
# dp
class Solution2(object):
    def goodBinaryStrings(self, minLength, maxLength, oneGroup, zeroGroup):
        """
        :type minLength: int
        :type maxLength: int
        :type oneGroup: int
        :type zeroGroup: int
        :rtype: int
        """
        MOD = 10**9+7
        dp = [0]*(maxLength+1)
        dp[0] = 1
        for i in xrange(maxLength+1):
            if not dp[i]:
                continue
            if i+oneGroup < len(dp):
                dp[i+oneGroup] = (dp[i+oneGroup]+dp[i])%MOD
            if i+zeroGroup < len(dp):
                dp[i+zeroGroup] = (dp[i+zeroGroup]+dp[i])%MOD
        return reduce(lambda total, i: (total+dp[i])%MOD, xrange(minLength, maxLength+1), 0)
