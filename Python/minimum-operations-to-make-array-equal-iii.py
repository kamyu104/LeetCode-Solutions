# Time:  O(nlogr), r = max(nums)
# Space: O(n)

import collections


# freq table, bit manipulation
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(lambda: collections.defaultdict(int))
        for x in nums:
            cnt[x.bit_length()][x] += 1
        if 1 in cnt[1] and cnt[1][1] == len(nums):
            return 0
        candidates = []
        for l, b in cnt.iteritems():
            if l == 1:
                continue
            total = sum(c for c in b.itervalues())
            for x, c in b.iteritems():
                if total-2*c >= 0:
                    continue
                candidates.append(x)
                break
        result = len(nums)
        for target in candidates:
            c = 0
            for x in nums:
                if x == target:
                    continue
                if x%target == 0 or target%x == 0:
                    c += 1
                else:
                    c += 2
            result = min(result, c)
        return result
