# Time:  O(1)
# Space: O(1)

class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return num > 0 and (num & (num - 1)) == 0 and \
               ((num & 0b01010101010101010101010101010101) == num)


# Time:  O(1)
# Space: O(1)
class Solution2(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        while num and not (num & 0b11):
            num >>= 2
        return (num == 1)


class Solution3(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        num = bin(num)
        return True if num[2:].startswith('1') and len(num[2:]) == num.count('0') and num.count('0') % 2 and '-' not in num else False

