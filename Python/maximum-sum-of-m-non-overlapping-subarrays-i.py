# Time:  O(nlogr)
# Space: O(n)

import collections


# prefix sum, dp, mono deque, wqs binary search, alien trick
class Solution(object):
    def maximumSum(self, nums, m, l, r):
        """
        :type nums: List[int]
        :type m: int
        :type l: int
        :type r: int
        :rtype: int
        """
        NEG_INF = float("-inf")
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def best_single():
            result = NEG_INF
            dq = collections.deque()
            for i in xrange(1, len(nums)+1):
                j = i-l
                if j >= 0:
                    while dq and prefix[dq[-1]] >= prefix[j]:
                        dq.pop()
                    dq.append(j)
                while dq and dq[0] < i-r:
                    dq.popleft()
                if dq:
                    result = max(result, prefix[i]-prefix[dq[0]])
            return result

        def f(x):
            def better(v1, c1, v2, c2):
                return v1 > v2 or (v1 == v2 and c1 < c2)

            dp = [[0]*2 for _ in xrange(len(nums)+1)]
            dq = collections.deque()
            for i in xrange(1, len(nums)+1):
                j = i-l
                if j >= 0:
                    while dq and better(dp[j][0]-prefix[j], dp[j][1], dp[dq[-1]][0]-prefix[dq[-1]], dp[dq[-1]][1]):
                        dq.pop()
                    dq.append(j)
                while dq and dq[0] < i-r:
                    dq.popleft()
                dp[i] = dp[i-1]
                if dq:
                    new_dp = [((dp[dq[0]][0]-prefix[dq[0]])+prefix[i])-x, dp[dq[0]][1]+1]
                    if better(new_dp[0], new_dp[1], dp[i][0], dp[i][1]):
                        dp[i] = new_dp
            return dp[-1]

        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        single = best_single()
        dp, cnt = f(0)
        if not cnt:
            return single
        if cnt <= m:
            return dp
        mx = single
        assert(f(mx)[1] <= m)
        x = binary_search(1, mx, lambda x: f(x)[1] <= m)
        return f(x)[0]+m*x


# Time:  O(n * m)
# Space: O(n)
import collections


# prefix sum, dp, mono deque
class Solution2(object):
    def maximumSum(self, nums, m, l, r):
        """
        :type nums: List[int]
        :type m: int
        :type l: int
        :type r: int
        :rtype: int
        """        
        NEG_INF = float("-inf")
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        result = NEG_INF
        dp = [0]*(len(nums)+1)
        for _ in xrange(m):
            new_dp = [NEG_INF]*(len(nums)+1)
            dq = collections.deque()
            for i in xrange(1, len(nums)+1):
                new_dp[i] = new_dp[i-1]
                j = i-l
                if j >= 0 and dp[j] is not NEG_INF:
                    while dq and dp[dq[-1]]-prefix[dq[-1]] <= dp[j]-prefix[j]:
                        dq.pop()
                    dq.append(j)
                while dq and dq[0] < i-r:
                    dq.popleft()
                if dq:
                    new_dp[i] = max(new_dp[i], (dp[dq[0]]-prefix[dq[0]])+prefix[i])
            dp = new_dp
            result = max(result, dp[-1])
        return result
