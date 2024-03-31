# Time:  O(nlogr) = O(n * 30)
# Space: O(logr) = O(30)

# freq table, two pointers
class Solution(object):
    def minimumSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def update(x, d, curr):
            for i in xrange(len(cnt)):
                if x < (1<<i):
                    break
                if not (x&(1<<i)):
                    continue
                if cnt[i] == 0:
                    curr ^= 1<<i
                cnt[i] += d
                if cnt[i] == 0:
                    curr ^= 1<<i
            return curr

        total = reduce(lambda x, y: x|y, nums)
        if total < k:
            return -1
        cnt = [0]*total.bit_length()
        result = len(nums)
        left = curr = 0
        for right in xrange(len(nums)):
            curr = update(nums[right], +1, curr)
            while left <= right and curr >= k:
                result = min(result, right-left+1)
                curr = update(nums[left], -1, curr)
                left += 1
        return result 
