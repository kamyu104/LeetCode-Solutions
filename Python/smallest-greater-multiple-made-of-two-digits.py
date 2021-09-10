# Time:  sum(O(l * 2^l) for l in range(1, 11)) = O(20 * 2^10) = O(1)
# Space: O(1)

class Solution(object):
    def findInteger(self, k, digit1, digit2):
        """
        :type k: int
        :type digit1: int
        :type digit2: int
        :rtype: int
        """
        MAX_NUM_OF_DIGITS = 10
        INT_MAX = 2**31-1

        if digit1 < digit2:
            digit1, digit2 = digit2, digit1
        total = 2
        for l in xrange(1, MAX_NUM_OF_DIGITS+1):
            for mask in xrange(total):
                curr, bit = 0, total>>1
                while bit:
                    curr = curr*10 + (digit1 if mask&bit else digit2)
                    bit >>= 1
                if k < curr <= INT_MAX and curr%k == 0:
                    return curr
            total <<= 1
        return -1
