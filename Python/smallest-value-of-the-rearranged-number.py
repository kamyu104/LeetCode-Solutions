# Time:  O(logn)
# Space: O(logn)

# greedy
class Solution(object):
    def smallestNumber(self, num):
        """
        :type num: int
        :rtype: int
        """
        sign = 1 if num >= 0 else -1
        nums = sorted(str(abs(num)), reverse=(sign == -1))
        i = next((i for i in xrange(len(nums)) if nums[i] != '0'), 0)
        nums[0], nums[i] = nums[i], nums[0]
        return sign*int("".join(nums))
