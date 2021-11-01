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


# Time:  O((k + m) * log(m * MAX_NUM)) ~ O(k * m * log(m * MAX_NUM))
# Space: O(m)
class Solution2(object):
    def kthSmallest(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: int
        """        
        def countArraysHaveSumLessOrEqual(mat, k, r, target):  # Time: O(k + m) ~ O(k * m)
            if target < 0:
                return 0
            if r == len(mat):
                return 1
            result = 0
            for c in xrange(len(mat[0])):
                cnt = countArraysHaveSumLessOrEqual(mat, k-result, r+1, target-mat[r][c])
                if not cnt:
                    break
                result += cnt
                if result > k:
                    break
            return result
        
        max_num = max(x for row in mat for x in row)
        left, right = len(mat), len(mat)*max_num
        while left <= right:
            mid = left + (right-left)//2
            cnt = countArraysHaveSumLessOrEqual(mat, k, 0, mid)
            if cnt >= k:
                right = mid-1
            else:
                left = mid+1
        return left

