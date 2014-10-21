# Time:  O(n^2) ~ O(n^4)
# Space: O(n^2)
#
# Given an array S of n integers, 
# are there elements a, b, c, and d in S such that a + b + c + d = target?
# Find all unique quadruplets in the array which gives the sum of target.
#
# Note:
# Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
# The solution set must not contain duplicate quadruplets.
# For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
#
#   A solution set is:
#    (-1,  0, 0, 1)
#    (-2, -1, 1, 2)
#    (-2,  0, 0, 2)
#

class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, nums, target):
        nums, result, lookup = sorted(nums), [], {}
        for i in range(0, len(nums) - 1):
            for j in range(i + 1, len(nums)): 
                if nums[i] + nums[j] not in lookup:
                    lookup[nums[i] + nums[j]] = []
                lookup[nums[i] + nums[j]].append([i, j])

        for i in lookup.keys():
            if target - i in lookup:
                for x in lookup[i]:
                    for y in lookup[target -i]:
                        [a, b], [c, d] = x, y
                        if a is not c and a is not d and b is not c and b is not d:
                            quad = sorted([nums[a], nums[b], nums[c], nums[d]])
                            if quad not in result:
                                result.append(quad)
        return sorted(result)

if __name__ == '__main__':
    result = Solution().fourSum([1, 0, -1, 0, -2, 2], 0)
    print result
