# Time:  O(n^2)
# Space: O(n^2)

# memoization
class Solution(object):
    def maxOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def memoization(left, right, target, lookup):
            if not right-left+1 >= 2:
                return 0
            if lookup[left][right] == -1:
                lookup[left][right] = max(1+memoization(left+2, right-0, target, lookup) if nums[left]+nums[left+1]   == target else 0,
                                          1+memoization(left+1, right-1, target, lookup) if nums[left]+nums[right]    == target else 0,
                                          1+memoization(left+0, right-2, target, lookup) if nums[right-1]+nums[right] == target else 0)
            return lookup[left][right] 

        return max(memoization(0, len(nums)-1, target, [[-1]*(len(nums)) for _ in xrange(len(nums))]) for target in {nums[0]+nums[1], nums[0]+nums[-1], nums[-2]+nums[-1]})
