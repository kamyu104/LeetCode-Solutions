class Solution:
    # @return an integer
    def reverse(self, x):
        ans = 0
        if x >= 0:
            while x:
               ans = ans * 10 + x % 10
               x /= 10
            return ans
        else:
            return -self.reverse(-x)