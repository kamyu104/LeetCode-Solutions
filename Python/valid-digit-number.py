# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def validDigit(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: bool
        """
        result = False
        while n:
            n, r = divmod(n, 10)
            if r != x:
                continue
            if not n:
                return False
            result = True
        return result


# Time:  O(logn)
# Space: O(logn)
# math
class Solution2(object):
    def validDigit(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: bool
        """
        digits = map(int, str(n))
        return x != digits[0] and x in digits
