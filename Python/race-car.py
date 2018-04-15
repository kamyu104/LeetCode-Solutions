# Time : O(nlogn), n is the value of the target
# Space: O(n)

# Your car starts at position 0 and speed +1 on an infinite number line.
# (Your car can go into negative positions.)
#
# Your car drives automatically according to a sequence of
# instructions A (accelerate) and R (reverse).
#
# When you get an instruction "A", your car does the following:
# position += speed, speed *= 2.
#
# When you get an instruction "R", your car does the following:
# if your speed is positive then speed = -1 , otherwise speed = 1.
# (Your position stays the same.)
#
# For example, after commands "AAR", your car goes to
# positions 0->1->3->3, and your speed goes to 1->2->4->-1.
#
# Now for some target position, say the length of the shortest
# sequence of instructions to get there.
#
# Example 1:
# Input:
# target = 3
# Output: 2
# Explanation:
# The shortest instruction sequence is "AA".
# Your position goes from 0->1->3.
# Example 2:
# Input:
# target = 6
# Output: 5
# Explanation:
# The shortest instruction sequence is "AAARA".
# Your position goes from 0->1->3->7->7->6.
#
# Note:
# - 1 <= target <= 10000.

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def racecar(self, target):
        dp = [0] * (target+1)
        for i in xrange(1, target+1):
            # 2^(k-1) <= i < 2^k
            k = i.bit_length()

            # case 1. drive exactly i at best
            #         seq(i) = A^k
            if i == 2**k-1:
                dp[i] = k
                continue

            # case 2. drive cross i at 2^k-1, and turn back to i
            #         seq(i) = A^k -> R -> seq(2^k-1 - i)
            dp[i] = k+1 + dp[2**k-1 - i]

            # case 3. drive less then 2^k-1, and turn back some distance,
            #         and turn back again to make the direction is the same
            #         seq(i) = shortest(seq(i), A^(k-1) -> R -> A^j -> R ->
            #                                   seq(i - (2^(k-1)-1) + (2^j-1)),
            #                  where 0 <= j < k-1)
            #         => dp[i] = min(dp[i], (k-1) + 1 + j + 1 +
            #                               dp[i - (2**(k-1)-1) + (2**j-1)])
            for j in xrange(k-1):
                dp[i] = min(dp[i], k+j+1 + dp[i - 2**(k-1) + 2**j])

        return dp[-1]
