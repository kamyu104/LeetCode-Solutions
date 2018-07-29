# Time:  O(logn)
# Space: O(1)

# A positive integer is magical if it is divisible by either A or B.
#
# Return the N-th magical number.
# Since the answer may be very large, return it modulo 10^9 + 7.
#
# Example 1:
#
# Input: N = 1, A = 2, B = 3
# Output: 2
# Example 2:
#
# Input: N = 4, A = 2, B = 3
# Output: 6
# Example 3:
#
# Input: N = 5, A = 2, B = 4
# Output: 10
# Example 4:
#
# Input: N = 3, A = 6, B = 4
# Output: 8
#
# Note:
# - 1 <= N <= 10^9
# - 2 <= A <= 40000
# - 2 <= B <= 40000

class Solution(object):
    def nthMagicalNumber(self, N, A, B):
        """
        :type N: int
        :type A: int
        :type B: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        def check(A, B, N, lcm, target):
            return target//A + target//B - target//lcm >= N

        lcm = A*B // gcd(A, B)
        left, right = min(A, B), max(A, B)*N
        while left <= right:
            mid = left + (right-left)//2
            if check(A, B, N, lcm, mid):
                right = mid-1
            else:
                left = mid+1
        return left % (10**9 + 7)
