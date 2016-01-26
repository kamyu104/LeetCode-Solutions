# Time:  O(n^2)
# Space: O(1)

# Given an index k, return the kth row of the Pascal's triangle.
# 
# For example, given k = 3,
# Return [1,3,3,1].
# 
# Note:
# Could you optimize your algorithm to use only O(k) extra space?
#

class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        result = [0] * (rowIndex + 1)
        for i in xrange(rowIndex + 1):
            old = result[0] = 1
            for j in xrange(1, i + 1):
                old, result[j] = result[j], old + result[j]
        return result


# Time:  O(n^2)
# Space: O(n)
class Solution2:
    # @return a list of integers
    def getRow(self, rowIndex):
        result = [1]
        for i in range(1, rowIndex + 1):
            result = [1] + [result[j - 1] + result[j] for j in xrange(1, i)] + [1]
        return result


if __name__ == "__main__":
    print Solution().getRow(3)
