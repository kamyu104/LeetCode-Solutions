# Time:  O(nlogn)
# Space: O(1)

# sort, dp
class Solution(object):
    def maxSelectedElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        result = 1
        dp = [1]*2  # dp[i]: the maximum length of a consecutive sequence ending with x+i, where x is the last visited value
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1]:
                dp[1] = dp[0]+1
            elif nums[i] == nums[i-1]+1:
                dp[0] += 1
                dp[1] += 1
            elif nums[i] == nums[i-1]+2:
                dp[0] = dp[1]+1
                dp[1] = 1
            else:
                dp[0] = dp[1] = 1
            result = max(result, dp[0], dp[1])
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections


# sort, dp
class Solution2(object):
    def maxSelectedElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        dp = collections.defaultdict(int)
        dp[nums[0]] = dp[nums[0]+1] = 1
        for i in xrange(1, len(nums)):
            if nums[i] == nums[i-1]:
                dp[nums[i]+1] = dp[nums[i]]+1
            elif nums[i] == nums[i-1]+1:
                dp[nums[i]+1] = dp[nums[i]]+1
                dp[nums[i]] = dp[nums[i]-1]+1
            elif nums[i] == nums[i-1]+2:
                dp[nums[i]] = dp[nums[i]-1]+1
                dp[nums[i]+1] = 1
            else:
                dp[nums[i]] = dp[nums[i]+1] = 1
        return max(dp.itervalues())


# Time:  O(nlogn)
# Space: O(n)
import collections


# sort, dp
class Solution3(object):
    def maxSelectedElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        dp = collections.defaultdict(int)
        for x in nums:
            dp[x+1] = dp[x]+1
            dp[x] = dp[x-1]+1
        return max(dp.itervalues())
