# Time:  O(n)
# Space: O(1)

# two pointers, sliding window
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mx = max(nums)
        result = left = cnt = 0
        for right in xrange(len(nums)):
            cnt += int(nums[right] == mx)
            while cnt == k:
                cnt -= int(nums[left] == mx)
                left += 1
            result += left
        return result


# Time:  O(n)
# Space: O(1)
# two pointers, sliding window
class Solution2(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mx = max(nums)
        result = (len(nums)+1)*len(nums)//2
        left = cnt = 0
        for right in xrange(len(nums)):
            cnt += int(nums[right] == mx)
            while cnt == k:
                cnt -= int(nums[left] == mx)
                left += 1
            result -= right-left+1
        return result
