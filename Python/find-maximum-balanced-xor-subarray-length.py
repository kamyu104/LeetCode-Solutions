# Time:  O(n)
# Space: O(n)

# hash table, prefix sum
class Solution(object):
    def maxBalancedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = total = bal = 0
        lookup = collections.defaultdict(int)
        lookup[(total, bal)] = -1
        for i, x in enumerate(nums):
            total ^= x
            bal += (1 if x%2 else -1)
            if (total, bal) not in lookup:
                lookup[total, bal] = i
            else:
                result = max(result, i-lookup[total, bal])
        return result
