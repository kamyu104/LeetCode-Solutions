# Time:  O(nlogn)
# Space: O(logn)

# Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
#
# You need to return the number of important reverse pairs in the given array.
#
# Example1:
#
# Input: [1,3,2,3,1]
# Output: 2
# Example2:
#
# Input: [2,4,3,5,1]
# Output: 3
# Note:
# The length of the given array will not exceed 50,000.
# All the numbers in the input array are in the range of 32-bit integer.
# Show Company Tags
# Show Tags
# Hide Similar Problems

class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def merge(nums, start, mid, end):
            r = mid + 1
            tmp = []
            for i in xrange(start, mid + 1):
                while r <= end and nums[i] > nums[r]:
                    tmp.append(nums[r])
                    r += 1
                tmp.append(nums[i])
            nums[start:start+len(tmp)] = tmp

        def countAndMergeSort(nums, start, end):
            if end - start <= 0:
                return 0

            mid = start + (end - start) / 2
            count = countAndMergeSort(nums, start, mid) + countAndMergeSort(nums, mid + 1, end)
            r = mid + 1
            for i in xrange(start, mid + 1):
                while r <= end and nums[i] > nums[r] * 2:
                    r += 1
                count += r - (mid + 1)
            merge(nums, start, mid, end)
            return count

        return countAndMergeSort(nums, 0, len(nums) - 1)
