# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def minimumNumbers(self, num, k):
        """
        :type num: int
        :type k: int
        :rtype: int
        """
        return next((i for i in xrange(1, (min(num//k, 10) if k else 1)+1) if (num-i*k)%10 == 0), -1) if num else 0
