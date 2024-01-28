# Time:  O(nlogr)
# Space: O(1)

# bitmasks, greedy
class Solution(object):
    def minOrAfterOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        l = max(nums).bit_length()
        mask = (1<<l)-1
        for i in reversed(xrange(l)):
            result <<= 1
            curr, cnt = mask, 0
            for x in nums:
                curr &= x>>i
                if curr&~result:
                    cnt += 1
                else:
                    curr = mask
            if cnt > k:
                result += 1
        return result
