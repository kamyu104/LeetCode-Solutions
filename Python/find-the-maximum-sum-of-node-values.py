# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maximumValueSum(self, nums, k, edges):
        """
        :type nums: List[int]
        :type k: int
        :type edges: List[List[int]]
        :rtype: int
        """
        result = parity = 0
        diff = float("inf")
        for x in nums:
            y = x^k
            result += max(x, y)
            parity ^= int(x < y)
            diff = min(diff, abs(x-y))
        return result-parity*diff
