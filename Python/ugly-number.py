# Time:  O(logn) = O(1)
# Space: O(1)

class Solution(object):
    # @param {integer} num
    # @return {boolean}
    def isUgly(self, num):
        if num == 0:
            return False
        for i in [2, 3, 5]:
            while num % i == 0:
                num /= i
        return num == 1

