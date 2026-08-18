# Time:  O(logk)
# Space: O(1)

# math
class Solution(object):
    def kthDigit(self, k):
        """
        :type k: int
        :rtype: int
        """
        def digit(x, i):
            for _ in xrange(i):
                x, r = divmod(x, 10)
            return r
            
        k -= 1
        base = l = 1
        while 9*base*l <= k:
            k -= 9*base*l
            base *= 10
            l += 1
        q, r = divmod(k, l)
        d = base+q
        result = digit(d, l-r)
        return result if r != l-1 or (d//10)%2 == 0 else 9-result
