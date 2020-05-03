# Time:  O(m * klogk)
# Space: O(k)

import heapq


class Solution(object):
    def kthSmallest(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: int
        """
        def kSmallestPairs(nums1, nums2, k):
            result, min_heap = [], []
            for c in xrange(min(len(nums1), k)):
                heapq.heappush(min_heap, (nums1[c]+nums2[0], 0))
                c += 1
            while len(result) != k and min_heap:
                total, c = heapq.heappop(min_heap)
                result.append(total)
                if c+1 == len(nums2):
                    continue
                heapq.heappush(min_heap, (total-nums2[c]+nums2[c+1], c+1))
            return result

        result = mat[0]
        for r in xrange(1, len(mat)):
            result = kSmallestPairs(result, mat[r], k)
        return result[k-1]
