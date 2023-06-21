# Time:  O(logn)
# Space: O(1)

# string, bitmasks
class Solution(object):
    def isFascinating(self, n):
        """
        :type n: int
        :rtype: bool
        """
        lookup = [0]
        def check(x):
            while x:
                x, d = divmod(x, 10)
                if d == 0 or lookup[0]&(1<<d):
                    return False
                lookup[0] |= (1<<d)
            return True
    
        return check(n) and check(2*n) and check(3*n)


# Time:  O(logn)
# Space: O(logn)
# string
class Solution2(object):
    def isFascinating(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s = str(n)+str(2*n)+str(3*n)
        return '0' not in s and len(s) == 9 and len(set(s)) == 9
