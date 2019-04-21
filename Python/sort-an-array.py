# Time:  O(nlogn)
# Space: O(n)

# merge sort solution
class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def mergeSort(start, end, lower, upper, nums):
            if end - start <= 1:
                return
            mid = start + (end - start) / 2
            mergeSort(start, mid, lower, upper, nums)
            mergeSort(mid, end, lower, upper, nums)
            r = mid
            tmp = []
            for i in xrange(start, mid):
                while r < end and nums[r] < nums[i]:
                    tmp.append(nums[r])
                    r += 1
                tmp.append(nums[i])
            nums[start:start+len(tmp)] = tmp

        mergeSort(0, len(nums), float("-inf"), float("inf"), nums)
        return nums
