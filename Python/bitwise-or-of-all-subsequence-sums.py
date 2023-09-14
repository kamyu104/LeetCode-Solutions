# Time:  O(n)
# Space: O(1)

# bit manipulation
class Solution(object):
    def subsequenceSumOr(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = prefix = 0
        for x in nums:
            prefix += x
            result |= x|prefix
        return result


# Time:  O(nlogn)
# Space: O(1)
# bit manipulation
class Solution2(object):
    def subsequenceSumOr(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = cnt = 0
        for i in xrange(64):
            cnt >>= 1
            for x in nums:
                cnt += (x>>i)&1
            if cnt:
                result |= 1<<i
        return result
