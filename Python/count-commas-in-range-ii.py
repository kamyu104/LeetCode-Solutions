# Time:  O(logn)
# Space: O(1)

# math
class Solution(object):
    def countCommas(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt, base = 0, 1
        while base*1000 <= n:
            base *= 1000
            cnt += 1
        result, base = 0, 1
        for i in xrange(cnt):
            base *= 1000
            result += n-base+1
        return result
