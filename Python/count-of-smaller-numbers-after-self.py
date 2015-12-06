# Time:  O(nlogn)
# Space: O(n)

# You are given an integer array nums and you have to 
# return a new counts array. The counts array has the 
# property where counts[i] is the number of smaller 
# elements to the right of nums[i].
#
# Example:
#
# Given nums = [5, 2, 6, 1]
#
# To the right of 5 there are 2 smaller elements (2 and 1).
# To the right of 2 there is only 1 smaller element (1).
# To the right of 6 there is 1 smaller element (1).
# To the right of 1 there is 0 smaller element.
# Return the array [2, 1, 1, 0].

class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def binarySearch(A, target, compare):
            start, end = 0, len(A) - 1
            while start <= end:
                mid = start + (end - start) / 2
                if compare(target, A[mid]):
                    end = mid - 1
                else:
                    start = mid + 1
            return start

        class BIT(object):
            def __init__(self, n):
                self.__bit = [0] * n

            def add(self, i, val):
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)
    
            def query(self, i):
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret
        
        sorted_nums, nth_smallest = sorted(nums), [0] * len(nums)
        for i, num in enumerate(nums):
            nth_smallest[i] = binarySearch(sorted_nums, num, lambda x, y: x <= y)

        ans, bit= [0] * len(nums), BIT(len(nums) + 1)
        for i in reversed(xrange(len(nums))):
            ans[i] = bit.query(nth_smallest[i])
            bit.add(nth_smallest[i] + 1, 1)
        return ans
  
