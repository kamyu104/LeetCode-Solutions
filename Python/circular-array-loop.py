# Time:  O(n)
# Space: O(1)

class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def next_index(nums, i):
            return (i + nums[i]) % len(nums)

        for i in xrange(len(nums)):
            if nums[i] == 0:
                continue

            slow, fast = i, i
            while nums[next_index(nums, slow)] * nums[i] > 0 and \
                  nums[next_index(nums, fast)] * nums[i] > 0 and \
                  nums[next_index(nums, next_index(nums, fast))] * nums[i] > 0:
                slow = next_index(nums, slow)
                fast = next_index(nums, next_index(nums, fast))
                if slow == fast:
                    if slow == next_index(nums, slow):
                        break
                    return True

            slow, val = i, nums[i]
            while nums[slow] * val > 0:
                tmp = next_index(nums, slow)
                nums[slow] = 0
                slow = tmp

        return False

