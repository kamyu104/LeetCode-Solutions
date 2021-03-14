# Time:  O(n)
# Space: O(n)

class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = curr = nums[k]
        left = right = k
        while left-1 >= 0 or right+1 < len(nums):
            # choosing larger one to expand is always better than or equal to choosing smaller one
            if (nums[left-1] if left-1 >= 0 else 0) <= (nums[right+1] if right+1 < len(nums) else 0):
                right += 1
            else:
                left -= 1
            curr = min(curr, nums[left], nums[right])
            result = max(result, curr*(right-left+1))
        return result


# Time:  O(nlogn)
# Space: O(n)
import bisect


class Solution2(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def score(nums, k):
            prefix = [nums[k]]*(k+1)
            for i in reversed(xrange(k)):
                prefix[i] = min(prefix[i+1], nums[i])
            result = right = nums[k]
            for j in xrange(k+1, len(nums)):
                right = min(right, nums[j])
                i = bisect.bisect_left(prefix, right)
                if i >= 0:
                    result = max(result, right*(j-i+1))
            return result

        return max(score(nums, k), score(nums[::-1], len(nums)-1-k))
 
