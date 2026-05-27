# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def check(i, d):
            return all(nums[(i+j*d)%len(nums)] == j for j in xrange(len(nums)))

        idx = nums.index(0)
        if check(idx, +1):
            return min(idx, 1+(len(nums)-idx)+1)
        elif check(idx, -1):
            return min((idx+1)+1, 1+(len(nums)-(idx+1)))
        return -1


# Time:  O(n)
# Space: O(1)
# array
class Solution2(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def asc():
            return sum(nums[i] > nums[(i+1)%len(nums)] for i in xrange(len(nums))) <= 1

        def desc():
            return sum(nums[i] < nums[(i+1)%len(nums)] for i in xrange(len(nums))) <= 1

        idx = nums.index(0)
        if asc():
            return min(idx, 1+(len(nums)-idx)+1)
        elif desc():
            return min((idx+1)+1, 1+(len(nums)-(idx+1)))
        return -1
