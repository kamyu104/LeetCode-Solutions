# Time:  O(logn * log(logn))
# Space: O(1)

# For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
#
# Now given a string representing n, you should return the smallest good base of n in string format. 
#
# Example 1:
# Input: "13"
# Output: "3"
# Explanation: 13 base 3 is 111.
# Example 2:
# Input: "4681"
# Output: "8"
# Explanation: 4681 base 8 is 11111.
# Example 3:
# Input: "1000000000000000000"
# Output: "999999999999999999"
# Explanation: 1000000000000000000 base 999999999999999999 is 11.
# Note:
# The range of n is [3, 10^18].
# The string representing n is always valid and will not have leading zeros.

class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        num = int(n)
        max_len = int(math.log(num,2))
        for l in xrange(max_len, 1, -1):
            b = int(num ** (l**-1))
            if (b**(l+1)-1) // (b-1) == num:
                return str(b)
        return str(num-1)
