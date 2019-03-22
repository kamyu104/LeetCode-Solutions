# Time:  O(nlogs), s is the sum of nums
# Space: O(1)

# Minimize the largest subarray sum.
class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def canSplit(nums, m, s):
            cnt, curr_sum = 1, 0
            for num in nums:
                curr_sum += num
                if curr_sum > s:
                    curr_sum = num
                    cnt += 1
            return cnt <= m

        left, right = max(nums), sum(nums)
        while left <= right:
            mid = left + (right - left) / 2
            if canSplit(nums, m, mid):
                right = mid - 1
            else:
                left = mid + 1
        return left


# Time:  O(nlogs), s is the sum of nums
# Space: O(1)

# Maximize the smallest subarray sum.
class SolutionFindMaxMin(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def canSplit(nums, m, s):
            cnt, curr_sum = 1, 0
            for num in nums:
                curr_sum += num
                if curr_sum > s:
                    curr_sum = 0
                    cnt += 1
            return cnt <= m

        left, right = min(nums), sum(nums)
        while left <= right:
            mid = left + (right - left) / 2
            x = canSplit(nums, m, mid)
            if x:
                right = mid - 1
            else:
                left = mid + 1
        return left

    
# Time:  O(nlogs), s is the sum of nums
# Space: O(1)

# Maximize the smallest subarray sum.
class SolutionFindMaxMin2(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        def canSplit(nums, m, s):
            cnt, curr_sum = 0, 0
            for num in nums:
                curr_sum += num
                if curr_sum >= s:
                    curr_sum = 0
                    cnt += 1
            return cnt < m

        left, right = min(nums), sum(nums)
        for i in xrange(left, right+1):
            canSplit(nums, m, i)
        while left <= right:
            mid = left + (right - left) / 2
            x = canSplit(nums, m, mid)
            if x:
                right = mid - 1
            else:
                left = mid + 1
        return left - 1
