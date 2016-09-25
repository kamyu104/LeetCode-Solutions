# Time:  O(logn)
# Space: O(1)

# Given an integer, write an algorithm to convert it to hexadecimal.
# For negative integer, two’s complement method is used.
#
# IMPORTANT:
# You must not use any method provided by the library which converts/formats
# the number to hex directly. Such solution will result in disqualification of
# all your submissions to this problem. Users may report such solutions after the
# contest ends and we reserve the right of final decision and interpretation
# in the case of reported solutions.
#
# Note:
#
# All letters in hexadecimal (a-f) must be in lowercase.
# The hexadecimal string must not contain extra leading 0s. If the number is zero,
# it is represented by a single zero character '0'; otherwise,
# the first character in the hexadecimal string will not be the zero character.
# The given number is guaranteed to fit within the range of a 32-bit signed integer.
# You must not use any method provided by the library which converts/formats the number to hex directly.
# Example 1:
#
# Input:
# 26
#
# Output:
# "1a"
# Example 2:
#
# Input:
# -1
#
# Output:
# "ffffffff"

class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if not num:
            return "0"

        result = []
        while num and len(result) != 8:
            h = num & 15
            if h < 10:
                result.append(str(chr(ord('0') + h)))
            else:
                result.append(str(chr(ord('a') + h-10)))
            num >>= 4
        result.reverse()

        return "".join(result)
