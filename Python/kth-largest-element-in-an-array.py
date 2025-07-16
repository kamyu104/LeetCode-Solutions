# Time:  O(n) on average, using Median of Medians could achieve O(n) (Intro Select)
# Space: O(1)

from random import randint


# optimized for duplicated nums
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        nth_element(nums, k-1, compare=lambda a, b: a > b)
        return nums[k-1]


# Time:  O(n) on average, using Median of Medians could achieve O(n) (Intro Select)
# Space: O(1)
class Solution2(object):
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer}
    def findKthLargest(self, nums, k):
        left, right = 0, len(nums) - 1
        while left <= right:
            pivot_idx = randint(left, right)
            new_pivot_idx = self.PartitionAroundPivot(left, right, pivot_idx, nums)
            if new_pivot_idx == k - 1:
                return nums[new_pivot_idx]
            elif new_pivot_idx > k - 1:
                right = new_pivot_idx - 1
            else:  # new_pivot_idx < k - 1.
                left = new_pivot_idx + 1

    def PartitionAroundPivot(self, left, right, pivot_idx, nums):
        pivot_value = nums[pivot_idx]
        new_pivot_idx = left
        nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
        for i in xrange(left, right):
            if nums[i] > pivot_value:
                nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                new_pivot_idx += 1

        nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
        return new_pivot_idx

"""
This implementation maintains a min-heap of size k, ensuring that the smallest element in the heap is the k-th largest in the array. 
The time complexity is O(Nlogk), which is efficient for large arrays. 
"""

import heapq
class Solution3(object):
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Create a min-heap with the first k elements
        min_heap = nums[:k]
        heapq.heapify(min_heap)
        
        # Iterate through the remaining elements
        for num in nums[k:]:
            if num > min_heap[0]:  # Compare with the smallest element in the heap
                heapq.heappushpop(min_heap, num)  # Push new element and pop the smallest
        
        return min_heap[0]  # The root of the heap is the k-th largest element
