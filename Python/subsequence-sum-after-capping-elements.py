# Time:  O(nlogn + n * k + klogn) = O(nlogn + n * k)
# Space: O(k)

# sort, dp, bitmasks
class Solution(object):
    def subsequenceSumAfterCapping(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[bool]
        """
        result = [False]*len(nums)
        nums.sort()
        mask = (1<<(k+1))-1
        dp = 1
        i = 0
        for x in xrange(1, len(nums)+1):
            while i < len(nums) and nums[i] < x:
                dp |= (dp<<nums[i])&mask
                i += 1
            for j in xrange(max(k%x, k-(len(nums)-i)*x), k+1, x):
                if dp&(1<<j):
                    result[x-1] = True
                    break
        return result


# Time:  O(nlogn + n * k + klogn) = O(nlogn + n * k)
# Space: O(k)
# sort, dp
class Solution2(object):
    def subsequenceSumAfterCapping(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[bool]
        """
        result = [False]*len(nums)
        nums.sort()
        dp = [False]*(k+1)
        dp[0] = True
        i = 0
        for x in xrange(1, len(nums)+1):
            while i < len(nums) and nums[i] < x:
                for j in reversed(xrange(nums[i], k+1)):
                    dp[j] = dp[j] or dp[j-nums[i]]
                i += 1
            for j in xrange(max(k%x, k-(len(nums)-i)*x), k+1, x):
                if dp[j]:
                    result[x-1] = True
                    break
        return result
