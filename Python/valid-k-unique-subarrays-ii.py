# Time:  O(n + q)
# Space: O(n)

import collections
import random


# two pointers, hash table, prefix sum
class Solution(object):
    def validSubarrays(self, nums, k, l0, r0, q):
        """
        :type nums: List[int]
        :type k: int
        :type l0: int
        :type r0: int
        :type q: int
        :rtype: List[bool]
        """
        def min_left(k):
            result = [len(nums)]*len(nums)
            cnt = collections.defaultdict(int)
            left = 0
            for right in xrange(len(nums)):
                cnt[nums[right]] += 1
                while len(cnt) == k+1:
                    cnt[nums[left]] -= 1
                    if not cnt[nums[left]]:
                        del cnt[nums[left]]
                    left += 1
                if len(cnt) == k:
                    result[right] = left
            return result

        left = min_left(k)
        right = min_left(k-1)
        h = {}
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            if nums[i] not in h:
                h[nums[i]] = random.getrandbits(64)
            prefix[i+1] = prefix[i]^h[nums[i]]
        result = []
        l, r = l0, r0
        for _ in xrange(q):
            result.append((r-l+1)%2 == 0 and prefix[r+1]^prefix[l] == 0 and left[r] <= l < right[r])
            g = l+r if result[-1] else r-l
            l, r = (l^g)%len(nums), (r^g)%len(nums)
            if l > r:
                l, r = r, l
        return result
