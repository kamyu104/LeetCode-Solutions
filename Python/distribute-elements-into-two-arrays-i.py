# Time:  O(n)
# Space: O(n)

# array
class Solution(object):
    def resultArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        a, b = [nums[0]], [nums[1]]
        for i in xrange(2, len(nums)):
            if a[-1] > b[-1]:
                a.append(nums[i])
            else:
                b.append(nums[i])
        return a+b
