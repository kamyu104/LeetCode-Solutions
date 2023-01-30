# Time:  O(n)
# Space: O(n)

class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ak = float("-inf")
        stk = []
        for i in reversed(xrange(len(nums))):
            if nums[i] < ak:
                return True
            while stk and stk[-1] < nums[i]:
                ak = stk.pop()
            stk.append(nums[i])
        return False


# Time:  O(n^2)
# Space: O(1)
class Solution_TLE(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        for k in xrange(len(nums)):
            valid = False
            for j in xrange(k):
                if nums[j] < nums[k]:
                    valid = True
                elif nums[j] > nums[k]:
                    if valid:
                        return True
        return False
