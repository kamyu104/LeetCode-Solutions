# Time:  O(1)
# Space: O(1)

class Solution(object):
    def nthPersonGetsNthSeat(self, n):
        """
        :type n: int
        :rtype: float
        """
        # p(k) = 1 * (prob that 1th passenger takes his own seat) +
        #        0 * (prob that 1th passenger takes kth one's seat) +
        #        1 * (prob that 1th passenger takes the others' seat) * 
        #            (prob that the first k-1 passengers get a seat
        #             which is not kth one's seat)
        #      = 1/k + p(k-1)*(k-2)/k
        #
        # p(1) = 1
        # p(2) = 1/2 + p(1) * (2-2)/2 = 1/2
        # p(3) = 1/3 + p(2) * (3-2)/3 = 1/3 + 1/2 * (3-2)/3 = 1/2
        # ...
        # p(n) = 1/n + 1/2 * (n-2)/n = (2+n-2)/(2n) = 1/2
        return 0.5 if n != 1 else 1.0

# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def nthPersonGetsNthSeat(self, n):
        """
        :type n: int
        :rtype: float
        """
        dp = [0.0]*2
        dp[0] = 1.0  # zero-indexed
        for i in xrange(2, n+1):
            dp[(i-1)%2] = 1.0/i+dp[(i-2)%2]*(i-2)/i
        return dp[(n-1)%2]
