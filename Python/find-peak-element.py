# Time:  O(logn)
# Space: O(1)
#
# A peak element is an element that is greater than its neighbors.
# 
# Given an input array where num[i] != num[i+1], find a peak element and return its index.
# 
# The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
# 
# You may imagine that num[-1] = num[n] = -infinite.
# 
# For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
#
# Note:
# Your solution should be in logarithmic complexity.
#

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        low, high = 0, len(num) - 1
        
        while low < high:
            mid = low + (high - low) / 2
            if (mid == 0 or num[mid - 1] <= num[mid]) and \
               (mid == len(num) - 1 or num[mid + 1] <= num[mid]):
                return mid
            elif mid > 0 and num[mid - 1] > num[mid]:
                high = mid - 1
            else:
                low = mid + 1
       
        return low

if __name__ == "__main__":
   # print Solution().findPeakElement([1,2,1])
    print Solution().findPeakElement([1,2,3, 1])
