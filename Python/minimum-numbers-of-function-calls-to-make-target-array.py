# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def popcount(n):
            result = 0
            while n:
                n &= n-1
                result += 1
            return result

        result, max_len = 0, 0
        for num in nums:
            result += popcount(num)
            max_len = max(max_len, max(num.bit_length(), 1))
        return result + max_len-1
            
