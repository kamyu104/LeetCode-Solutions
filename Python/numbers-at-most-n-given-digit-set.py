# Time:  O(logn)
# Space: O(logn)

# We have a sorted set of digits D, a non-empty subset of
# {'1','2','3','4','5','6','7','8','9'}.  (Note that '0' is not included.)
#
# Now, we write numbers using these digits, using each digit as many times as we want.
# For example, if D = {'1','3','5'}, we may write numbers such as '13', '551', '1351315'.
#
# Return the number of positive integers that can be written (using the digits of D) 
# that are less than or equal to N.
#
# Example 1:
#
# Input: D = ["1","3","5","7"], N = 100
# Output: 20
# Explanation: 
# The 20 numbers that can be written are:
# 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
# Example 2:
#
# Input: D = ["1","4","9"], N = 1000000000
# Output: 29523
# Explanation: 
# We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
# 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
# 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
# In total, this is 29523 integers that can be written using the digits of D.
#
# Note:
# - D is a subset of digits '1'-'9' in sorted order.
# - 1 <= N <= 10^9

class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        str_N = str(N)
        set_D = set(D)
        result = sum(len(D)**i for i in xrange(1, len(str_N)))
        i = 0
        while i < len(str_N):
            result += sum(c < str_N[i] for c in D) * (len(D)**(len(str_N)-i-1))
            if str_N[i] not in set_D:
                break
            i += 1
        return result + int(i == len(str_N))
