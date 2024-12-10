# Time:  O(n)
# Space: O(n)

# hash table, constructive algorithms
class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mn = min(nums)
        return len(set(nums))-int(mn == k) if mn >= k else -1
