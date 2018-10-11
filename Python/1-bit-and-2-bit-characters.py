# Time:  O(n)
# Space: O(1)

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        parity = 0
        for i in reversed(xrange(len(bits)-1)):
            if bits[i] == 0:
                break
            parity ^= bits[i]
        return parity == 0

