# Time:  O(logn)
# Space: O(logn)
# 
# Implement pow(x, n).
#

class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n < 0:
            return 1 / self.powRecu(x, -n)
        
        return self.powRecu(x, n)
    
    def powRecu(self, x, n):
        if n == 0:
            return 1.0
        
        if n % 2 == 0:
            return self.powRecu(x * x, n / 2)
        else:
            return x * self.powRecu(x * x, n / 2)

if __name__ == "__main__":
    print Solution().pow(3, 5)
    print Solution().pow(3, -5)