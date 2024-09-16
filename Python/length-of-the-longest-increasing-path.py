# Time:  O(nlogn)
# Space: O(n)

import bisect


# sort, binary search, longest increasing subsequence, lis
class Solution(object):
    def maxPathLength(self, coordinates, k):
        """
        :type coordinates: List[List[int]]
        :type k: int
        :rtype: int
        """
        def longest_increasing_subsequence(arr):
            result = []
            for x in arr:
                i = bisect.bisect_left(result, x)
                if i == len(result):
                    result.append(x)
                else:
                    result[i] = x
            return len(result)

        target = coordinates[k]
        coordinates.sort(key=lambda x: (x[0], -x[1]))
        left, right = [], []
        for x, y in coordinates:
            if x < target[0] and y < target[1]:
                left.append(y)
            elif x > target[0] and y > target[1]:
                right.append(y)
        return longest_increasing_subsequence(left)+1+longest_increasing_subsequence(right)
