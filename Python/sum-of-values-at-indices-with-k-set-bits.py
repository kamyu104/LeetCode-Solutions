# Time:  O(C(ceil(log2(n)), k))
# Space: O(1)

# bit manipulation, hakmem-175
class Solution(object):
    def sumIndicesWithKSetBits(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def next_popcount(n):  # reference: https://massivealgorithms.blogspot.com/2014/06/hakmem-item-175.html
            lowest_bit = n&-n
            left_bits = n+lowest_bit
            changed_bits = n^left_bits
            right_bits = (changed_bits//lowest_bit)>>2
            return left_bits|right_bits

        result = 0 
        i = (1<<k)-1
        while i < len(nums):
            result += nums[i]
            if i == 0:
                break
            i = next_popcount(i)
        return result


# Time:  O(n)
# Space: O(1)
# bit manipulation
class Solution2(object):
    def sumIndicesWithKSetBits(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def popcount(x):
            return bin(x)[1:].count('1')
        
        return sum(x for i, x in enumerate(nums) if popcount(i) == k)
