# Time:  O(log(logn)) = O(1)
# Space: O(1)

# bit manipulation
class Solution(object):
    def calculateScore(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        def popcount(n):
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555)
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
            n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F)
            n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF)
            n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF)
            return n

        s1, s2 = popcount(a), popcount(b)
        return s1*s2 if s1 >= s2 else s2//s1


# Time:  O(logn) = O(1)
# Space: O(1)
# bit manipulation
class Solution2(object):
    def calculateScore(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        def popcount(n):
            result = 0
            while n:
                n &= n-1
                result += 1
            return result

        s1, s2 = popcount(a), popcount(b)
        return s1*s2 if s1 >= s2 else s2//s1


# Time:  O(logn) = O(1)
# Space: O(logn) = O(1)
# bit manipulation
class Solution3(object):
    def calculateScore(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        def popcount(n):
            return bin(n).count('1')

        s1, s2 = popcount(a), popcount(b)
        return s1*s2 if s1 >= s2 else s2//s1
