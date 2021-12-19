# Time:  O(k * (n/k)log(n/k)) = O(nlog(n/k))
# Space: O(n/k)

import bisect


class Solution(object):
    def kIncreasing(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        def longest_non_decreasing_subsequence(arr):
            result = []
            for x in arr:
                right = bisect.bisect_right(result, x)
                if right == len(result):
                    result.append(x)
                else:
                    result[right] = x
            return len(result)

        return len(arr) - sum(longest_non_decreasing_subsequence((arr[j] for j in xrange(i, len(arr), k))) for i in xrange(k))
