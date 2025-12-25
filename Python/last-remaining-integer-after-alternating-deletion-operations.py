# Time:  O(1)
# Space: O(1)

# bitmasks
class Solution(object):
    def lastInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        MASK = 0xAAAAAAAAAAAAA
        return ((n-1)&MASK)+1


# Time:  O(logn)
# Space: O(1)
# bitmasks
class Solution(object):
    def lastInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = l = 1
        p = 0
        while n != 1:
            if p and not n%2:
                result += l
            n = (n+1)//2
            l <<= 1
            p ^= 1
        return result
