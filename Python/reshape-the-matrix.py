# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        if not nums or \
           r*c != len(nums) * len(nums[0]):
            return nums

        result = [[0 for _ in xrange(c)] for _ in xrange(r)]
        count = 0
        for i in xrange(len(nums)):
            for j in xrange(len(nums[0])):
                result[count/c][count%c] = nums[i][j]
                count += 1
        return result

