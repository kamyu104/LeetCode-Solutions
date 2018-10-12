# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        med = (len(nums) - 1) / 2
        nums[::2], nums[1::2] = nums[med::-1], nums[:med:-1]

# Time:  O(n) ~ O(n^2)
# Space: O(1)
# Tri Partition (aka Dutch National Flag Problem) with virtual index solution. (TLE)
from random import randint
class Solution2(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def findKthLargest(nums, k):
            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = randint(left, right)
                new_pivot_idx = partitionAroundPivot(left, right, pivot_idx, nums)
                if new_pivot_idx == k - 1:
                    return nums[new_pivot_idx]
                elif new_pivot_idx > k - 1:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k - 1.
                    left = new_pivot_idx + 1

        def partitionAroundPivot(left, right, pivot_idx, nums):
            pivot_value = nums[pivot_idx]
            new_pivot_idx = left
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            for i in xrange(left, right):
                if nums[i] > pivot_value:
                    nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                    new_pivot_idx += 1
            nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
            return new_pivot_idx

        def reversedTriPartitionWithVI(nums, val):
            def idx(i, N):
                return (1 + 2 * (i)) % N

            N = len(nums) / 2 * 2 + 1
            i, j, n = 0, 0, len(nums) - 1
            while j <= n:
                if nums[idx(j, N)] > val:
                    nums[idx(i, N)], nums[idx(j, N)] = nums[idx(j, N)], nums[idx(i, N)]
                    i += 1
                    j += 1
                elif nums[idx(j, N)] < val:
                    nums[idx(j, N)], nums[idx(n, N)] = nums[idx(n, N)], nums[idx(j, N)]
                    n -= 1
                else:
                    j += 1

        mid = (len(nums) - 1) / 2
        findKthLargest(nums, mid + 1)
        reversedTriPartitionWithVI(nums, nums[mid])

