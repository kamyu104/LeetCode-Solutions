# Time:  O(nlogn)
# Space: O(n)

import collections


# binary search, two pointers, sliding window
class Solution(object):
    def medianOfUniquenessArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(k):
            result = 0
            cnt = collections.Counter()
            left = 0
            for right in xrange(len(nums)):
                cnt[nums[right]] += 1
                while len(cnt) == k+1:
                    cnt[nums[left]] -= 1
                    if cnt[nums[left]] == 0:
                        del cnt[nums[left]]
                    left += 1
                result += right-left+1
            return result >= total-result

        total = (len(nums)+1)*len(nums)//2
        return binary_search(1, len(set(nums)), check)
