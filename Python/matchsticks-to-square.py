# Time:  O(n * s * 2^n), s is the number of subset of which sum equals to side length.
# Space: O(n * (2^n + s))

# Remember the story of Little Match Girl? By now, you know exactly
# what matchsticks the little match girl has, please find out a way
# you can make one square by using up all those matchsticks.
# You should not break any stick, but you can link them up,
# and each matchstick must be used exactly one time.
#
# Your input will be several matchsticks the girl has,
# represented with their stick length.
# Your output will either be true or false,
# to represent whether you could make one square using all the matchsticks the little match girl has.
#
# Example 1:
# Input: [1,1,2,2,2]
# Output: true
#
# Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
# Example 2:
# Input: [3,3,3,3,4]
# Output: false
#
# Explanation: You cannot find a way to form a square with all the matchsticks.
# Note:
# The length sum of the given matchsticks is in the range of 0 to 10^9.
# The length of the given matchstick array will not exceed 15.

class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total_len = sum(nums)
        if total_len % 4:
            return False

        side_len = total_len / 4
        fullset = (1 << len(nums)) - 1

        used_subsets = []
        valid_half_subsets = [0] * (1 << len(nums))

        for subset in xrange(fullset+1):
            subset_total_len = 0
            for i in xrange(len(nums)): 
                if subset & (1 << i):
                    subset_total_len += nums[i]

            if subset_total_len == side_len:
                for used_subset in used_subsets:
                    if (used_subset & subset) == 0:
                        valid_half_subset = used_subset | subset
                        valid_half_subsets[valid_half_subset] = True
                        if valid_half_subsets[fullset ^ valid_half_subset]:
                            return True
                used_subsets.append(subset)
            
        return False
