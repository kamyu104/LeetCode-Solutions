# Time:  O(n)
# Space: O(n)


class Solution(object):

    def twoSum(self, nums: list[int], target: int) -> list[int]:
        """Find indices of the two numbers such that they add up to target."""
        lookup = {}
        for i, num in enumerate(nums):
            if target - num in lookup:
                return [lookup[target - num], i]
            lookup[num] = i
        return []

    def twoSum2(self, nums: list[int], target: int) -> list[int]:
        """Alternative single-pass approach using hash map."""
        seen = {}
        for i, v in enumerate(nums):
            if target - v in seen:
                return [seen[target - v], i]
            seen[v] = i
        return []