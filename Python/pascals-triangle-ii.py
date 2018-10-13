# Time:  O(n^2)
# Space: O(1)

class Solution(object):
    # @return a list of integers
    def getRow(self, rowIndex):
        result = [0] * (rowIndex + 1)
        for i in xrange(rowIndex + 1):
            old = result[0] = 1
            for j in xrange(1, i + 1):
                old, result[j] = result[j], old + result[j]
        return result

    def getRow2(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        row = [1]
        for _ in range(rowIndex):
            row = [x + y for x, y in zip([0] + row, row + [0])]
        return row

    def getRow3(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0: return [1]
        res = [1, 1]

        def add(nums):
            res = nums[:1]
            for i, j in enumerate(nums):
                if i < len(nums) - 1:
                    res += [nums[i] + nums[i + 1]]
            res += nums[:1]
            return res

        while res[1] < rowIndex:
            res = add(res)
        return res


# Time:  O(n^2)
# Space: O(n)
class Solution2(object):
    # @return a list of integers
    def getRow(self, rowIndex):
        result = [1]
        for i in range(1, rowIndex + 1):
            result = [1] + [result[j - 1] + result[j] for j in xrange(1, i)] + [1]
        return result


