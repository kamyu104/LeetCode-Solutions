# Time:  O(nlogk)
# Space: O(k)

# You have k lists of sorted integers in ascending order.
# Find the smallest range that includes at least one number from each of the k lists.
#
# We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
#
# Example 1:
# Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
# Output: [20,24]
# Explanation: 
# List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
# List 2: [0, 9, 12, 20], 20 is in range [20,24].
# List 3: [5, 18, 22, 30], 22 is in range [20,24].
# Note:
# The given list may contain duplicates, so ascending order means >= here.
# 1 <= k <= 3500
# -10^5 <= value of elements <= 10^5.
# For Java users, please note that the input type has been changed to List<List<Integer>>.
# And after you reset the code template, you'll see this point.

class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        left, right = float("inf"), float("-inf")
        min_heap = []
        for row in nums:
            left = min(left, row[0])
            right = max(right, row[0])
            it = iter(row)
            heapq.heappush(min_heap, (next(it, None), it))
        
        result = (left, right)
        while min_heap:
            (val, it) = heapq.heappop(min_heap)    
            val = next(it, None)
            if val is None:
                break
            heapq.heappush(min_heap, (val, it))
            left, right = min_heap[0][0], max(right, val);
            if right - left < result[1] - result[0]:
                result = (left, right)
        return result
