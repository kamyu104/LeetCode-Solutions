# Time:  O(nlogs), s is the sum of nums
# Space: O(1)

class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def check(nums, m, s):
            cnt, curr_sum = 1, 0
            for num in nums:
                curr_sum += num
                if curr_sum > s:
                    curr_sum = num
                    cnt += 1
            return cnt <= m

        left, right = max(nums), sum(nums)
        while left <= right:
            mid = left + (right - left) // 2
            if check(nums, m, mid):
                right = mid - 1
            else:
                left = mid + 1
        return left
