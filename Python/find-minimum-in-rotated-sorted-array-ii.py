# Time:  O(logn)
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
           
        while low < high:
            if num[low] < num[high - 1] or low == high - 1:
                return num[low]
            
            mid = low + (high - low) / 2
                
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                if mid == high - 1:
                    return num[mid]
                else:
                    high = mid + 1
            else:
                for i in reversed(xrange(low, mid)):
                    if num[i] > num[mid]:
                        return num[i + 1]
                    if num[i] < num[mid]:
                        return num[i]
                for i in xrange(mid + 1, high):
                    if num[i] > num[mid]:
                        if i == high - 1:
                            return num[0]
                        else:
                            return num[i + 1]
                    if num[i] < num[mid]:
                        return num[i]
                return num[mid]

        return num[low]

if __name__ == "__main__":
    print Solution().findMin([3, 1, 1, 2, 2, 3])