# Time:  O(n^3)
# Space: O(n)

# Given a string S of digits, such as S = "123456579",
# we can split it into a Fibonacci-like sequence [123, 456, 579].
#
# Formally, a Fibonacci-like sequence is a list F of non-negative
# integers such that:
#
# 0 <= F[i] <= 2^31 - 1,
# (that is, each integer fits a 32-bit signed integer type);
# F.length >= 3;
# and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
# Also, note that when splitting the string into pieces,
# each piece must not have extra leading zeroes,
# except if the piece is the number 0 itself.
#
# Return any Fibonacci-like sequence split from S,
# or return [] if it cannot be done.
#
# Example 1:
#
# Input: "123456579"
# Output: [123,456,579]
# Example 2:
#
# Input: "11235813"
# Output: [1,1,2,3,5,8,13]
# Example 3:
#
# Input: "112358130"
# Output: []
# Explanation: The task is impossible.
# Example 4:
#
# Input: "0123"
# Output: []
# Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
# Example 5:
#
# Input: "1101111"
# Output: [110, 1, 111]
# Explanation: The output [11, 0, 11, 11] would also be accepted.
#
# Note:
# - 1 <= S.length <= 200
# - S contains only digits.

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        def startswith(S, k, x):
            y = 0
            for i in xrange(k, len(S)):
                y = 10*y + int(S[i])
                if y == x:
                    return i-k+1
                elif y > x:
                    break
            return 0

        MAX_INT = 2**31-1
        a = 0
        for i in xrange(len(S)-2):
            a = 10*a + int(S[i])
            b = 0
            for j in xrange(i+1, len(S)-1):
                b = 10*b + int(S[j])
                fib = [a, b]
                k = j+1
                while k < len(S):
                    if fib[-2] > MAX_INT-fib[-1]:
                        break
                    c = fib[-2]+fib[-1]
                    length = startswith(S, k, c)
                    if length == 0:
                        break
                    fib.append(c)
                    k += length
                else:
                    return fib
                if b == 0:
                    break
            if a == 0:
                break
        return []
