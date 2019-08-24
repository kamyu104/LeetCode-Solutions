# Time:  O(nlogn)
# Space: O(n)

# merge sort solution
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergeSort(start, end, nums):
            if end - start <= 1:
                return
            mid = start + (end - start) // 2
            mergeSort(start, mid, nums)
            mergeSort(mid, end,  nums)
            right = mid
            tmp = []
            for left in xrange(start, mid):
                while right < end and nums[right] < nums[left]:
                    tmp.append(nums[right])
                    right += 1
                tmp.append(nums[left])
            nums[start:start+len(tmp)] = tmp

        mergeSort(0, len(nums), nums)
        return nums


# Time:  O(nlogn), on average
# Space: O(logn)
import random
# quick sort solution
class Solution2(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def kthElement(nums, left, k, right, compare):
            def PartitionAroundPivot(left, right, pivot_idx, nums, compare):
                new_pivot_idx = left
                nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
                for i in xrange(left, right):
                    if compare(nums[i], nums[right]):
                        nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                        new_pivot_idx += 1

                nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
                return new_pivot_idx

            right -= 1
            while left <= right:
                pivot_idx = random.randint(left, right)
                new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums, compare)
                if new_pivot_idx == k:
                    return
                elif new_pivot_idx > k:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k.
                    left = new_pivot_idx + 1
                    
        def quickSort(start, end, nums):
            if end - start <= 1:
                return
            mid = start + (end - start) / 2
            kthElement(nums, start, mid, end, lambda a, b: a < b)
            quickSort(start, mid, nums)
            quickSort(mid, end, nums)

        quickSort(0, len(nums), nums)
        return nums
