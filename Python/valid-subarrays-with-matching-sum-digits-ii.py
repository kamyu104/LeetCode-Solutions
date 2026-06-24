# Time:  O(nlogr)
# Space: O(n)

# prefix sum, two pointers
class Solution(object):
    def countValidSubarrays(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        result = 0
        base = 1
        while x*base <= prefix[-1]:
            cnt = [0]*10
            left = right = 0
            for i in xrange(len(nums)):
                while prefix[right] <= prefix[i+1]-x*base:
                    cnt[prefix[right]%10] += 1
                    right += 1
                while prefix[left] <= prefix[i+1]-(x+1)*base:
                    cnt[prefix[left]%10] -= 1
                    left += 1
                result += cnt[(prefix[i+1]-x)%10]
            base *= 10
        return result
