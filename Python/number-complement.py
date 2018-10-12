# Time:  O(1)
# Space: O(1)

class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        return 2 ** (len(bin(num)) - 2) - 1 - num


class Solution2(object):
    def findComplement(self, num):
        i = 1
        while i <= num:
            i <<= 1
        return (i - 1) ^ num


class Solution3(object):
    def findComplement(self, num):
        bits = '{0:b}'.format(num)
        complement_bits = ''.join('1' if bit == '0' else '0' for bit in bits)
        return int(complement_bits, 2)

