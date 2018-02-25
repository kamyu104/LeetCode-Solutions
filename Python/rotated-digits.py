# Time:  O(n)
# Space: O(n)

# X is a good number if after rotating each digit individually by 180 degrees,
# we get a valid number that is different from X.
# A number is valid if each digit remains a digit after rotation.
# 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other;
# 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number.
#
# Now given a positive number N, how many numbers X from 1 to N are good?
#
# Example:
# Input: 10
# Output: 4
# Explanation: 
# There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
# Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
#
# Note:
# - N  will be in range [1, 10000].

class Solution(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        INVALID, SAME, DIFF = 0, 1, 2
        same, diff = [0, 1, 8], [2, 5, 6, 9]
        dp = [0] * (N+1)
        dp[0] = SAME
        for i in xrange(N//10+1):
            if dp[i] != INVALID:
                for j in same:
                    if i*10+j <= N:
                        dp[i*10+j] = max(SAME, dp[i])
                for j in diff:
                    if i*10+j <= N:
                        dp[i*10+j] = DIFF
        return dp.count(DIFF)
    

# Time:  O(nlogn) = O(n), because O(logn) = O(32) by this input
# Space: O(logn) = O(1)
class Solution2(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        invalid, diff = set(['3', '4', '7']), set(['2', '5', '6', '9'])
        result = 0
        for i in xrange(N+1):
            lookup = set(list(str(i)))
            if invalid & lookup:
                continue
            if diff & lookup:
                result += 1
        return result
        
