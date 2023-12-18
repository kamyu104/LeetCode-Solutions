# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers, sliding window
class Solution(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result = left = curr = 0
        for right in xrange(len(nums)):
            curr += nums[right]-nums[(left+right)//2]
            if not curr <= k:
                curr -= nums[((left+1)+right)//2]-nums[left]
                left += 1
        return right-left+1


# Time:  O(nlogn)
# Space: O(1)
# sort, two pointers, sliding window
class Solution2(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        result = left = curr = 0
        for right in xrange(len(nums)):
            curr += nums[right]-nums[(left+right)//2]
            while not curr <= k:
                curr -= nums[((left+1)+right)//2]-nums[left]
                left += 1
            result = max(result, right-left+1)
        return result
