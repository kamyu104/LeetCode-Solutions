# Time:  O(logn)
# Space: O(1)
#
# Suppose a sorted array is rotated at some pivot unknown to you beforehand.
#
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
#
# Find the minimum element.
#
# You may assume no duplicate exists in the array.
#

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num)
           
        while low < high - 1 and  num[low] >= num[high - 1]:
            mid = low + (high - low) / 2
                
            if num[mid] > num[low]:
                low = mid + 1
            elif num[mid] < num[low]:
                if mid == high - 1:
                    return num[mid]
                else:
                    high = mid + 1
            else:
                return num[mid]

        return num[low]

class Solution2:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low, high = 0, len(num) - 1
           
        while low < high and num[low] >= num[high]:
            mid = low + (high - low) / 2
            
            if num[mid] >= num[low]:
                low = mid + 1
            else:
                high = mid

        return num[low]

if __name__ == "__main__":
    print Solution().findMin([1])
    print Solution().findMin([1, 2])
    print Solution().findMin([2, 1])
    print Solution().findMin([3, 1, 2])
    print Solution().findMin([2, 3, 1])