# Time:  O(n * r)
# Space: O(r)

# freq table, two pointers
class Solution(object):
    def maxSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def check(x):
            return all(not cnt[y] or not cnt[x-y] or (y == x-y and cnt[y] <= 1) for y in xrange(1, x//2+1)) and \
                   all(not cnt[y] or not cnt[x+y] for y in xrange(1, len(cnt)-x))
 
        cnt = [0]*(max(nums)+1)
        result = left = 0
        for right, x in enumerate(nums):
            while not check(x):
                cnt[nums[left]] -= 1
                left += 1
            cnt[x] += 1
            result = max(result, right-left+1)
        return result
