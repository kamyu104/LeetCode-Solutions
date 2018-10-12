# Time:  O(1)
# Space: O(1)

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

