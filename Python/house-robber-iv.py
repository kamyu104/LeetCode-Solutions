# Time:  O(nlogn)
# Space: O(n)

# binary search, greedy
class Solution(object):
    def minCapability(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def check(x):
            cnt = i = 0
            while i < len(nums):
                if nums[i] <= x:
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= k

        sorted_nums = sorted(set(nums))
        left, right = 0, len(sorted_nums)-1
        while left <= right:
            mid = left + (right-left)//2
            if check(sorted_nums[mid]):
                right = mid-1
            else:
                left = mid+1
        return sorted_nums[left]


# Time:  O(nlogr)
# Space: O(1)
# binary search, greedy
class Solution2(object):
    def minCapability(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def check(x):
            cnt = i = 0
            while i < len(nums):
                if nums[i] <= x:
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= k
    
        left, right = min(nums), max(nums)
        while left <= right:
            mid = left + (right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return left
