# Time:  O(m^2)
# Space: O(m)

import collections


# sort, dp
class Solution(object):
    def elevatorRequests(self, n, start, requests):
        """
        :type n: int
        :type start: int
        :type requests: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        lookup = collections.defaultdict(int)
        for a, f in requests:
            lookup[f] = max(lookup[f], a)
        pairs = sorted(lookup.items())
        if len(pairs) == 1:
            return max(abs(pairs[0][0]-start), pairs[0][1])
        dp = [[INF]*len(pairs) for _ in xrange(2)]
        dp[0][1] = max(abs(pairs[0][0]-start), pairs[0][1])
        dp[1][0] = max(abs(pairs[-1][0]-start), pairs[-1][1])
        result = INF
        for l in reversed(xrange(1, len(pairs))):
            new_dp = [[INF]*len(pairs) for _ in xrange(2)]
            for i in xrange(len(pairs)-l+1):
                j = i+l-1
                for s in xrange(2):
                    if dp[s][i] == INF:
                        continue
                    x = pairs[i-1][0] if s == 0 else pairs[j+1][0]
                    if l == 1:
                        result = min(result, max(dp[s][i]+abs(x-pairs[i][0]), pairs[i][1]))
                        continue
                    new_dp[0][i+1] = min(new_dp[0][i+1], max(dp[s][i]+abs(x-pairs[i][0]), pairs[i][1]))
                    new_dp[1][i] = min(new_dp[1][i], max(dp[s][i]+abs(x-pairs[j][0]), pairs[j][1]))
            dp = new_dp
        return result


# Time:  O(m^2 * logr)
# Space: O(m)
import collections


# sort, binary search, dp
class Solution2(object):
    def elevatorRequests(self, n, start, requests):
        """
        :type n: int
        :type start: int
        :type requests: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(x):
            dp = [[0 if pairs[i][1] <= x else INF for i in xrange(len(pairs))] for _ in xrange(2)]
            for l in xrange(1, len(pairs)):
                new_dp = [[INF]*len(pairs) for _ in xrange(2)]
                for i in xrange(len(pairs)-l+1):
                    j = i+l-1
                    if i-1 >= 0:
                        for t in (dp[0][i]+(pairs[i][0]-pairs[i-1][0]), dp[1][i]+(pairs[j][0]-pairs[i-1][0])):
                            if pairs[i-1][1] <= x-t:
                                new_dp[0][i-1] = min(new_dp[0][i-1], t)
                    if j+1 < len(pairs):
                        for t in (dp[1][i]+(pairs[j+1][0]-pairs[j][0]), dp[0][i]+(pairs[j+1][0]-pairs[i][0])):
                            if pairs[j+1][1] <= x-t:
                                new_dp[1][i] = min(new_dp[1][i], t)
                dp = new_dp
            return dp[0][0]+abs(pairs[0][0]-start) <= x or dp[1][0]+abs(pairs[-1][0]-start) <= x

        lookup = collections.defaultdict(int)
        for a, f in requests:
            lookup[f] = max(lookup[f], a)
        pairs = sorted(lookup.items())
        mx = max(a for _, a in pairs)
        diff1 = max(start-pairs[0][0], 0)
        diff2 = max(pairs[-1][0]-start, 0)
        left = max(mx, min(2*diff1+diff2, diff1+2*diff2))
        right = max(mx, min(abs(start-pairs[0][0]), abs(start-pairs[-1][0])))+(pairs[-1][0]-pairs[0][0])
        return binary_search(left, right, check)


# Time:  O(m^2 * 2^m)
# Space: O(m * 2^m)
import collections


# sort, bitmasks, dp
class Solution3(object):
    def elevatorRequests(self, n, start, requests):
        """
        :type n: int
        :type start: int
        :type requests: List[List[int]]
        :rtype: int
        """
        INF = float("inf")
        lookup = collections.defaultdict(int)
        for a, f in requests:
            lookup[f] = max(lookup[f], a)
        pairs = sorted(lookup.items())
        dp = [[INF]*len(pairs) for _ in xrange(1<<len(pairs))]
        for i in xrange(len(pairs)):
            dp[1<<i][i] = max(abs(pairs[i][0]-start), pairs[i][1])
        for mask in xrange(1, 1<<len(pairs)):
            for i in xrange(len(pairs)):
                if not (mask&(1<<i)) or dp[mask][i] == INF:
                    continue
                for j in xrange(len(pairs)):
                    if mask&(1<<j):
                        continue
                    dp[mask|(1<<j)][j] = min(dp[mask|(1<<j)][j], max(dp[mask][i]+abs(pairs[i][0]-pairs[j][0]), pairs[j][1]))
        return min(dp[-1])
