# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def gcdOfOddEvenSums(self, n):
        """
        :type n: int
        :rtype: int
        """
        # gcd((1+(2n-1))*n/2, (2+2n)*n/2) = gcd(n*n, n*(n+1)) = n * gcd(n, n+1) = n
        return n
