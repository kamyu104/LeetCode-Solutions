# Time:  O(r * (n + q)), r is the max of nums
# Space: O(r * n)

import itertools


class Solution(object):
    def minDifference(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [[0]*(max(nums)+1)]
        for num in nums:
            prefix.append(prefix[-1][:])
            prefix[-1][num] += 1
        result = []
        for l, r in queries:
            sub_nums = [num for cnt1, cnt2, num in itertools.izip(prefix[l], prefix[r+1], xrange(len(prefix[0]))) if cnt1 < cnt2]
            result.append(min([b-a for a, b in itertools.izip(sub_nums, itertools.islice(sub_nums, 1, len(sub_nums)))] or [-1]))
        return result


# Time:  O(r + n + q * r * logn), r is the max of nums
# Space: O(r + n)
import bisect


class Solution2(object):
    def minDifference(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        INF = float("inf")
        idxs = [[] for _ in xrange(max(nums)+1)]
        for i, num in enumerate(nums):
            idxs[num].append(i)
        result = []
        for l, r in queries:
            min_diff, prev = INF, -1
            for num in xrange(len(idxs)):
                i = bisect.bisect_left(idxs[num], l)
                if i < len(idxs[num]) and idxs[num][i] <= r:
                    if prev != -1:
                        min_diff = min(min_diff, num-prev)
                    prev = num
            result.append(min_diff if min_diff != INF else -1)
        return result
