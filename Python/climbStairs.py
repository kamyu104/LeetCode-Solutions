# Time:  O(n)
# Space: O(1)
#
# You are climbing a stair case. It takes n steps to reach to the top.
# 
# Each time you can either climb 1 or 2 steps. 
# In how many distinct ways can you climb to the top?
#
class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        prev, current = 0, 1
        for i in range(n):
            prev, current = current, prev + current, 
        return current

if __name__ == "__main__":
    result = Solution().climbStairs(2)
    print result