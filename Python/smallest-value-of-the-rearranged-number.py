# Time:  O(d), d is the number of digits
# Space: O(d)

# greedy, counting sort
class Solution(object):
    def smallestNumber(self, num):
        """
        :type num: int
        :rtype: int
        """
        def inplace_counting_sort(nums, reverse=False):  # Time: O(n)
            count = [0]*(max(nums)+1)
            for num in nums:
                count[num] += 1
            for i in xrange(1, len(count)):
                count[i] += count[i-1]
            for i in reversed(xrange(len(nums))):  # inplace but unstable sort
                while nums[i] >= 0:
                    count[nums[i]] -= 1
                    j = count[nums[i]]
                    nums[i], nums[j] = nums[j], ~nums[i]
            for i in xrange(len(nums)):
                nums[i] = ~nums[i]  # restore values
            if reverse:  # unstable sort
                nums.reverse()

        sign = 1 if num >= 0 else -1
        nums = map(int, list(str(abs(num))))
        inplace_counting_sort(nums, reverse=(sign == -1))
        i = next((i for i in xrange(len(nums)) if nums[i] != 0), 0)
        nums[0], nums[i] = nums[i], nums[0]
        return sign*int("".join(map(str, nums)))


# Time:  O(dlogd), d is the number of digits
# Space: O(d)
# greedy
class Solution2(object):
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
