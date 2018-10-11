from __future__ import print_function
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        reachable = 0
        for i, length in enumerate(A):
            if i > reachable:
                break
            reachable = max(reachable, i + length)
        return reachable >= len(A) - 1

if __name__ == "__main__":
    print(Solution().canJump([2,3,1,1,4]))
    print(Solution().canJump([3,2,1,0,4]))

