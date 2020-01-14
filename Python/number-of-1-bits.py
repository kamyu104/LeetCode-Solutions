# Time:  O(32), bit shift in python is not O(1), it's O(k), k is the number of bits shifted
#             , see https://github.com/python/cpython/blob/2.7/Objects/longobject.c#L3652
# Space: O(1)

class Solution(object):
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555)
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
        n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F)
        n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF)
        n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF)
        return n


# Time:  O(logn/4) = O(32/4 + 8*4) = O(32)
# Space: O(1) 
# https://github.com/gcc-mirror/gcc/blob/master/libgcc/libgcc2.c#L856
class Solution2(object):
    def __init__(self):
        self.__popcount_tab = \
        [ \
            0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5, \
            1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6, \
            1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6, \
            2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7, \
            1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6, \
            2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7, \
            2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7, \
            3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8 \
        ]

    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        result = 0
        while n:
            result += self.__popcount_tab[n & 0xff]
            n >>= 8
        return result

    
# Time:  O(logn) = O(32)
# Space: O(1)
class Solution3(object):
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        result = 0
        while n:
            n &= n - 1
            result += 1
        return result

