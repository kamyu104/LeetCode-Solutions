# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        left, right = -1, -2
        min_from_right, max_from_left = nums[-1], nums[0]
        for i in xrange(1, n):
            max_from_left = max(max_from_left, nums[i])
            min_from_right = min(min_from_right, nums[n-1-i])
            if nums[i] < max_from_left: right = i
            if nums[n-1-i] > min_from_right: left = n-1-i


# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = sorted(nums) #sort the list
        left, right = 0, len(nums) -1 #define left and right pointer
        while (nums[left] == a[left] or nums[right] == a[right]):
            if right - left <= 1:
                return 0
            if nums[left] == a[left]:
                left += 1
            if nums[right] == a[right]:
                right -= 1
        return right - left + 1

