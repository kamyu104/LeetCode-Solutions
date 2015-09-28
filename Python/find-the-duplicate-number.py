# Time:  O(n)
# Space: O(1)

# Two pointers method, same as Linked List Cycle II.
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        slow = nums[len(nums) - 1]
        fast = nums[nums[len(nums) - 1] - 1]

        while slow != fast:
            slow = nums[slow - 1]
            fast = nums[nums[fast - 1] - 1]
    
        slow   = nums[slow - 1]
        fast = nums[len(nums) - 1]
        while slow != fast:
            slow   = nums[slow - 1]
            fast = nums[fast - 1]
    
        return slow


# Time:  O(nlogn)
# Space: O(1)
# Binary search method.
class Solution2(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 1, len(nums) - 1

        while left <= right:
            mid = left + (right - left) / 2
            # Get count of num <= mid.
            count = 0
            for num in nums:
                if num <= mid:
                    count += 1
            if count > mid:
                right = mid - 1 
            else:
                left = mid + 1
        return left

# Time:  O(n)
# Space: O(n)
class Solution3(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        duplicate = 0
        # Mark the value as visited by negative.
        for num in nums:
            if nums[abs(num) - 1] > 0:
                nums[abs(num) - 1] *= -1
            else:
                duplicate = abs(num)
                break
        # Rollback the value.
        for num in nums:
            if nums[abs(num) - 1] < 0:
                nums[abs(num) - 1] *= -1
            else:
                break
        return duplicate
