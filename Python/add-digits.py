# Time:  O(1)
# Space: O(1)
#
# Given a non-negative integer num, repeatedly add
# all its digits until the result has only one digit.
#
# For example:
#
# Given num = 38, the process is like: 3 + 8 = 11,
# 1 + 1 = 2. Since 2 has only one digit, return it.
#
# Follow up:
# Could you do it without any loop/recursion in O(1)
# runtime?
#
# Hint:
#
# A naive implementation of the above process is trivial.
# Could you come up with other methods? 


class Solution:
    """
    :type num: int
    :rtype: int
    """
    def addDigits(self, num):
        return (num - 1) % 9 + 1 if num > 0 else 0


if __name__ == '__main__':
    s = Solution()
    r = s.addDigits(12345)
    print r
