# Time:  O(n + r)
# Space: O(r)

# freq table
class Solution(object):
    def sumDivisibleByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mx = max(nums)
        cnt = [0]*(mx+1)
        for x in nums:
            cnt[x] += 1
        return sum(x for x in nums if cnt[x]%k == 0)


# Time:  O(n)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def sumDivisibleByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        return sum(x for x in nums if cnt[x]%k == 0)
