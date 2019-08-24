# Time:  O(n) ~ O(n^2), O(n) on average.
# Space: O(1)

import random


# quick select solution
class Solution(object):
    def largestSumAfterKNegations(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        def kthElement(nums, k, compare):
            def PartitionAroundPivot(left, right, pivot_idx, nums, compare):
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if compare(nums[i], nums[right]):
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = random.randint(left, right)
                new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums, compare)
                if new_pivot_idx == k:
                    return
                elif new_pivot_idx > k:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k.
                    left = new_pivot_idx + 1
                    
        kthElement(A, K, lambda a, b: a < b)
        remain = K
        for i in xrange(K):
            if A[i] < 0:
                A[i] = -A[i]
                remain -= 1
        return sum(A) - ((remain)%2)*min(A)*2


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def largestSumAfterKNegations(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        remain = K
        for i in xrange(K):
            if A[i] >= 0:
                break
            A[i] = -A[i]
            remain -= 1
        return sum(A) - (remain%2)*min(A)*2
