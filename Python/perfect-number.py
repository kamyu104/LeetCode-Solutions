# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False

        sqrt_num = int(num ** 0.5)
        total = sum(i+num//i for i in xrange(1, sqrt_num+1) if num%i == 0)
        if sqrt_num ** 2 == num:
            total -= sqrt_num
        return total - num == num

