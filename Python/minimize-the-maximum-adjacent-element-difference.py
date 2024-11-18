# Time:  O(nlogr)
# Space: O(1)

# binary search
class Solution(object):
    def minDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(d):
            prev = cnt = 0
            for i in xrange(len(nums)):
                if nums[i] == -1:
                    cnt += 1
                    continue
                if prev and cnt and min(max(abs(prev-x), abs(nums[i]-x)) for x in (left+d, right-d)) > d and (cnt == 1 or (right-d)-(left+d) > d):
                    return False
                prev = nums[i]
                cnt = 0
            return True

        max_diff, left, right = 0, float("inf"), 0
        for i in xrange(len(nums)):  
            if nums[i] != -1:
                if i+1 < len(nums) and nums[i+1] != -1:
                    max_diff = max(max_diff, abs(nums[i]-nums[i+1]))  
                continue          
            if i-1 < len(nums) and nums[i-1] != -1:
                left = min(left, nums[i-1])
                right = max(right, nums[i-1])
            if i+1 < len(nums) and nums[i+1] != -1:
                left = min(left, nums[i+1])
                right = max(right, nums[i+1])
        return binary_search(max_diff, (right-left)//2, check)
