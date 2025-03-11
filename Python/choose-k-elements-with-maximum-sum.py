# Time:  O(nlogn)
# Space: O(n)

import heapq


# sort, greedy, two pointers, heap
class Solution(object):
    def findMaxSum(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        result = [0]*len(nums1)
        min_heap = []
        idxs = range(len(nums1))
        idxs.sort(key=lambda x: nums1[x])
        total = j = 0
        for i in xrange(len(idxs)):
            while nums1[idxs[j]] < nums1[idxs[i]]:
                total += nums2[idxs[j]]
                heapq.heappush(min_heap, nums2[idxs[j]])
                if len(min_heap) == k+1:
                    total -= heapq.heappop(min_heap)
                j += 1
            result[idxs[i]] = total            
        return result
