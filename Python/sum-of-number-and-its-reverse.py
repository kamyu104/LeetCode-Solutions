# Time:  O(nlogn)
# Space: O(logn)

# brute force
class Solution(object):
    def sumOfNumberAndReverse(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return any(x+int(str(x)[::-1]) == num for x in xrange(num//2, num+1))
