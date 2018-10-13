# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in xrange(len(nums)):
            if nums[abs(nums[i]) - 1] > 0:
                nums[abs(nums[i]) - 1] *= -1

        result = []
        for i in xrange(len(nums)):
            if nums[i] > 0:
                result.append(i+1)
            else:
                nums[i] *= -1
        return result

    def findDisappearedNumbers2(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return list(set(range(1, len(nums) + 1)) - set(nums))

    def findDisappearedNumbers3(self, nums):
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            nums[index] = - abs(nums[index])

        return [i + 1 for i in range(len(nums)) if nums[i] > 0]


