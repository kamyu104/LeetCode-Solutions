# Time:  O(nlogn)
# Space: O(n)

import bisect


# binary search, longest increasing subsequence, lis
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def longest_non_increasing_subsequence(arr):
            result = []
            for x in arr:
                right = bisect.bisect_right(result, -x)
                if right == len(result):
                    result.append(-x)
                else:
                    result[right] = -x
            return len(result)
        
        return longest_non_increasing_subsequence(nums)
