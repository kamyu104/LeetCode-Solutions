# Time:  O(logn)
# Space: O(1)
#
# Implement int sqrt(int x).
# 
# Compute and return the square root of x.
#

class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        if x < 2:
            return x
        
        low, high = 1, x / 2
        while high >= low:
            mid = low + (high - low) / 2
            if x / mid < mid:
                high = mid - 1
            else:
                low = mid + 1
        return high

if __name__ == "__main__":
    print Solution().sqrt(10)
            