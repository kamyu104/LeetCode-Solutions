# Time:  O(n!)
# Space: O(n)
#
# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
# 
# For example,
# If n = 4 and k = 2, a solution is:
# 
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]
#

class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        result = []
        self.combineDFS(n, result, 0, [], k)
        return result
    
    def combineDFS(self, n, result, start, intermediate, k):
        if k == 0:
            result.append(intermediate)
        for i in range(start, n):
            self.combineDFS(n, result, i + 1, intermediate + [i + 1], k - 1)

if __name__ == "__main__":
    result = Solution().combine(4, 2)
    print result