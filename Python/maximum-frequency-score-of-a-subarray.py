# Time:  O(n)
# Space: O(n)

import collections


# two pointers, sliding window freq table, hash table
class Solution(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        lookup = {}
        def powmod(n, p):
            if (n, p) not in lookup:
                lookup[n, p] = (lookup[n, p-1]*n)%MOD if p >= 2 else n%MOD  # assumed powmod(n, p-1) was accessed before powmod(n, p)
            return lookup[n, p]

        result = curr = 0
        cnt = collections.Counter()
        for i in xrange(len(nums)):
            if i >= k:
                curr = (curr-powmod(nums[i-k], cnt[nums[i-k]]))%MOD
                cnt[nums[i-k]] -= 1
                if cnt[nums[i-k]]:
                    curr = (curr+powmod(nums[i-k], cnt[nums[i-k]]))%MOD
            if cnt[nums[i]]:
               curr = (curr-powmod(nums[i], cnt[nums[i]]))%MOD
            cnt[nums[i]] += 1
            curr = (curr+powmod(nums[i], cnt[nums[i]]))%MOD
            if i >= k-1:
                result = max(result, curr)
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections


# two pointers, sliding window, freq table
class Solution2(object):
    def maxFrequencyScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        MOD = 10**9+7
        result = curr = 0
        cnt = collections.Counter()
        for i in xrange(len(nums)):
            if i >= k:
                curr = (curr-pow(nums[i-k], cnt[nums[i-k]], MOD))%MOD
                cnt[nums[i-k]] -= 1
                if cnt[nums[i-k]]:
                    curr = (curr+pow(nums[i-k], cnt[nums[i-k]], MOD))%MOD
            if cnt[nums[i]]:
               curr = (curr-pow(nums[i], cnt[nums[i]], MOD))%MOD
            cnt[nums[i]] += 1
            curr = (curr+pow(nums[i], cnt[nums[i]], MOD))%MOD
            if i >= k-1:
                result = max(result, curr)
        return result
