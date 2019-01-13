# Time:  O(n) on average
# Space: O(n)

from random import randint


class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        def kthElement(nums, k, f):
            def PartitionAroundPivot(left, right, pivot_idx, nums, f):
                pivot_value = f(nums[pivot_idx])
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if f(nums[i]) < pivot_value:
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = randint(left, right)
                new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums, f)
                if new_pivot_idx == k - 1:
                    return
                elif new_pivot_idx > k - 1:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k - 1.
                    left = new_pivot_idx + 1
                    
        kthElement(points, K, lambda point: point[0]**2 + point[1]**2)
        return points[:K]
