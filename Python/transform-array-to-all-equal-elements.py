# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def canMakeEqual(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        def check(target):
            cnt = 0
            sign = 1
            for i in xrange(len(nums)):
                if nums[i]*sign == target:
                    sign = 1
                    continue
                cnt += 1
                if i+1 == len(nums) or cnt > k:
                    return False
                sign = -1
            return True

        return check(1) or check(-1)
