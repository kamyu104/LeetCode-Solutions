# Time:  O(nlogn)
# Space: O(n)

# Given an integer array nums, return the number of range
# sums that lie in [lower, upper] inclusive.
# Range sum S(i, j) is defined as the sum of the elements
# in nums between indices i and j (i <= j), inclusive.
#
# Note:
# A naive algorithm of O(n^2) is trivial. You MUST do better than that.
#
# Example:
# Given nums = [-2, 5, -1], lower = -2, upper = 2,
# Return 3.
# The three ranges are : [0, 0], [2, 2], [0, 2] and
# their respective sums are: -2, -1, 2.

# Divide and Conquer solution.
class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        def countAndMergeSort(sums, start, end, lower, upper):
            if end - start <= 1:  # The size of range [start, end) less than 2 is always with count 0.
                return 0
            mid = start + (end - start) / 2
            count = countAndMergeSort(sums, start, mid, lower, upper) + \
                    countAndMergeSort(sums, mid, end, lower, upper);
            j, k, r = mid, mid, mid
            tmp = []
            for i in xrange(start, mid):
                # Count the number of range sums that lie in [lower, upper].
                while k < end and sums[k] - sums[i] < lower:
                    k += 1
                while j < end and sums[j] - sums[i] <= upper:
                    j += 1
                count += j - k
    
                # Merge the two sorted arrays into tmp.
                while r < end and sums[r] < sums[i]:
                    tmp.append(sums[r])
                    r += 1
                tmp.append(sums[i])
            # Copy tmp back to sums.
            sums[start:start+len(tmp)] = tmp
            return count

        sums = [0] * (len(nums) + 1)
        for i in xrange(len(nums)):
            sums[i + 1] = sums[i] + nums[i]
        return countAndMergeSort(sums, 0, len(sums), lower, upper)
