# Time:  O(1)
# Space: O(1)

# There is a special square room with mirrors on each of the four walls.
# Except for the southwest corner, there are receptors on each of
# the remaining corners,
# numbered 0, 1, and 2.
#
# The square room has walls of length p,
# and a laser ray from the southwest corner first meets
# the east wall at a distance q from the 0th receptor.
#
# Return the number of the receptor that the ray meets first.
# (It is guaranteed that the ray will meet a receptor eventually.)
#
# Example 1:
#
# Input: p = 2, q = 1
# Output: 2
# Explanation: The ray meets receptor 2 the first time it gets reflected back
# to the left wall.
#
# Note:
# - 1 <= p <= 1000
# - 0 <= q <= p


class Solution(object):
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        # explanation commented in the following solution
        return 2 if (p & -p) > (q & -q) else 0 if (p & -p) < (q & -q) else 1


# Time:  O(log(max(p, q))) = O(1) due to 32-bit integer
# Space: O(1)
class Solution2(object):
    def mirrorReflection(self, p, q):
        """
        :type p: int
        :type q: int
        :rtype: int
        """
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        lcm = p*q // gcd(p, q)
        # let a = lcm / p, b = lcm / q
        if lcm // p % 2 == 1:
            if lcm // q % 2 == 1:
                return 1  # a is odd, b is odd <=> (p & -p) == (q & -q)
            return 2  # a is odd, b is even <=> (p & -p) > (q & -q)
        return 0  # a is even, b is odd <=> (p & -p) < (q & -q)
