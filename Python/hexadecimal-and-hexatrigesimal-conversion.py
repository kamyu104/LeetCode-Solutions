# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def concatHex36(self, n):
        """
        :type n: int
        :rtype: str
        """
        LOOKUP = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        def convert(n, l):
            result = []
            while n:
                n, r = divmod(n, l)
                result.append(LOOKUP[r])
            result.reverse()
            return "".join(result)
        
        return convert(n**2, 16)+convert(n**3, 36)
