# Time:  O(n^0.25 * logn)
# Space: O(logn)

# Let's say a positive integer is a superpalindrome
# if it is a palindrome, and it is also the square of a palindrome.
#
# Now, given two positive integers L and R (represented as strings),
# return the number of superpalindromes in the inclusive range [L, R].
#
# Example 1:
#
# Input: L = "4", R = "1000"
# Output: 4
# Explanation: 4, 9, 121, and 484 are superpalindromes.
# Note that 676 is not a superpalindrome: 26 * 26 = 676,
# but 26 is not a palindrome.
#
# Note:
# - 1 <= len(L) <= 18
# - 1 <= len(R) <= 18
# - L and R are strings representing integers in the range [1, 10^18).
# - int(L) <= int(R)
                                                        
class Solution(object):
    def superpalindromesInRange(self, L, R):
        """
        :type L: str
        :type R: str
        :rtype: int
        """
        def is_palindrome(k):
            return str(k) == str(k)[::-1]

        K = int((10**((len(R)+1)*0.25)))
        l, r = int(L), int(R)

        result = 0

        # count odd length
        for k in xrange(K):
            s = str(k)
            t = s + s[-2::-1]
            v = int(t)**2
            if v > r:
                break
            if v >= l and is_palindrome(v):
                result += 1

        # count even length
        for k in xrange(K):
            s = str(k)
            t = s + s[::-1]
            v = int(t)**2
            if v > r:
                break
            if v >= l and is_palindrome(v):
                result += 1

        return result
