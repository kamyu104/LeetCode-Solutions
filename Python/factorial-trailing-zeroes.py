# Time:  O(logn) = O(1)
# Space: O(1)

class Solution(object):
    # @return an integer
    def trailingZeroes(self, n):
        result = 0
        while n > 0:
            result += n / 5
            n /= 5
        return result

