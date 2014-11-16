# Time:  O(logn) ~ O(n)
# Space: O(1)
#
# Follow up for "Find Minimum in Rotated Sorted Array":
# What if duplicates are allowed?
# 
# Would this affect the run-time complexity? How and why?
# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
# 
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
# 
# Find the minimum element.
# 
# The array may contain duplicates.
#


class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num)
           
        while low < high - 1 and num[low] >= num[high - 1]:
            mid = low + (high - low) / 2
                
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                if mid == high - 1:
                    return num[mid]
                else:
                    high = mid + 1
            else:
                low += 1

        return num[low]

class Solution2:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num) - 1
           
        while low < high and num[low] >= num[high]:
            mid = low + (high - low) / 2
            
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                high = mid
            else:
                low += 1

        return num[low]

if __name__ == "__main__":
    print Solution().findMin([3, 1, 1, 2, 2, 3])
    print Solution2().findMin([2, 2, 2, 3, 3, 1])