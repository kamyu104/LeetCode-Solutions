# Time:  O(n)
# Space: O(1)
#
# Given an array of non-negative integers, you are initially positioned at the first index of the array.
# 
# Each element in the array represents your maximum jump length at that position.
# 
# Your goal is to reach the last index in the minimum number of jumps.
# 
# For example:
# Given array A = [2,3,1,1,4]
# 
# The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
#

# not pass on leetcode because of time limit
class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        jump_count = 0
        reachable = 0
        curr_reachable = 0
        for i, length in enumerate(A):
            if i > reachable:
                return -1
            if i > curr_reachable:
                curr_reachable = reachable
                jump_count += 1
            reachable = max(reachable, i + length)
        return jump_count

# Time:  O(n^2)
# Space: O(1)     
class Solution2:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        result, prev_reachable, reachable = 0, -1, 0
        while reachable > prev_reachable:
            if reachable >= len(A) - 1:
                return result
            result += 1
            prev_reachable = reachable
            for i, length in enumerate(A[:reachable + 1]):
                reachable = max(reachable, i + length)
        return -1

# when you on an index of nums, move to next index which can move farthest in range of this index reachable
# Time: O(log(n))
# Space: O(1)
class Solution3(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums[-1] = 2 ** 31
        nums2, l = [i + j for i, j in enumerate(nums)], len(nums) - 1

        def find_max_index(index):
            tmp = nums2[index:index + nums[index] + 1]
            return index + tmp.index(max(tmp))

        index, steps = 0, 0
        while True:
            index = find_max_index(index)
            if index:
                steps += 1
            if index == l:
                break
        return steps
    
if __name__ == "__main__":
    print Solution().jump([2,3,1,1,4])
    print Solution().jump([3,2,1,0,4])
