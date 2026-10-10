# Time:  O(nlogn)
# Space: O(n)

# sort, two pointers, dp
class Solution(object):
    def maxEarnings(self, meetings):
        """
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort()
        idxs = sorted(range(len(meetings)), key=lambda i: meetings[i][1])
        result = idx = 0
        best = float("-inf")
        dp = [0]*len(meetings)
        for i, (s, e, r) in enumerate(meetings):
            while meetings[idxs[idx]][1] <= s:
                best = max(best, dp[idxs[idx]]-meetings[idxs[idx]][1])
                idx += 1
            dp[i] = r+max(s+best, 0)
            result = max(result, dp[i])
        return result


# Time:  O(nlogn)
# Space: O(n)
import bisect


# sort, binary search, prefix sum, dp
class Solution2(object):
    def maxEarnings(self, meetings):
        """
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort(key=lambda x: x[1])
        ends = [x[1] for x in meetings]
        result = 0
        prefix = [float("-inf")]*(len(meetings)+1)
        for i, (s, e, r) in enumerate(meetings):
            dp = r+max(s+prefix[bisect.bisect_right(ends, s)], 0)
            result = max(result, dp)
            prefix[i+1] = max(prefix[i], dp-e)
        return result
