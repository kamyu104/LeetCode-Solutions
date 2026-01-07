# Time:  O(l * nlogn + 2^n * log(n * l) * n * logl + 3^n), n = len(lists), l = max(len(list) for list in lists)
# Space: O(n * l + 2^n)

import heapq


# dp, sort, binary search, submask enumeration
class Solution(object):
    def minMergeCost(self, lists):
        """
        :type lists: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def merge(lists):
            result = []
            min_heap = [(lists[i][0], i, 0) for i in xrange(len(lists))]
            heapq.heapify(min_heap)
            while min_heap:
                x, i, j = heapq.heappop(min_heap)
                result.append(x)
                if j+1 < len(lists[i]):
                    heapq.heappush(min_heap, (lists[i][j+1], i, j+1))
            return result

        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(x):
            return sum(bisect.bisect_right(lists[i], sorted_vals[x]) for i in range(len(lists)) if mask&(1<<i)) >= (dp1[mask]+1)//2

        dp1 = [0]*(1<<len(lists))
        for i in xrange(len(lists)):  # Time: O(2^n)
            dp1[1<<i] = len(lists[i])
        for mask in xrange(1, len(dp1)):  # Time: O(2^n)
            dp1[mask] = dp1[mask^(mask&-mask)]+dp1[mask&-mask]
        sorted_vals = merge(lists)  # Time: O(l * nlogn)
        sorted_vals = [sorted_vals[i] for i in xrange(len(sorted_vals)) if i+1 == len(sorted_vals) or sorted_vals[i+1] != sorted_vals[i]]
        dp2 = [0]*(1<<len(lists))
        for mask in xrange(1, len(dp2)):  # Time: O(2^n * log(n * l) * n * logl)
            dp2[mask] = sorted_vals[binary_search(0, len(sorted_vals)-1, check)]
        dp3 = [0]*(1<<len(lists))
        for mask in xrange(1, len(dp3)):  # Time: O(3^n)
            if mask&(mask-1) == 0:
                continue
            dp3[mask] = INF
            submask = (mask-1)&mask
            while submask > mask^submask:
                dp3[mask] = min(dp3[mask], dp3[submask]+dp3[mask^submask]+abs(dp2[submask]-dp2[mask^submask])+dp1[mask])
                submask = (submask-1)&mask
        return dp3[-1]
