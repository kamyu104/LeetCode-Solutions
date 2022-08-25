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

        result, max_len = 0, 1
        for num in nums:
            result += popcount(num)
            max_len = max(max_len, num.bit_length())
        return result + (max_len-1)
