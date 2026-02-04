# Time:  O(n * log(n * r)) = O(nlogn + nlogr), r = max(nums)
# Space: O(n)

import collections


# prefix sum, dp, convex hull trick, wqs binary search, alien trick
class Solution(object):
    def minPartitionScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(l1, l2, l3):
            return (l2[1]-l1[1])*(l2[0]-l3[0]) < (l3[1]-l2[1])*(l1[0]-l2[0])

        def max_lambda():
            mx, total = 0, prefix[-1]*(prefix[-1]+1)//2
            for i in xrange(1, len(nums)):
                c1, c2 = prefix[i], prefix[-1]-prefix[i]
                mx = max(mx, total-(c1*(c1+1)//2+c2*(c2+1)//2))
            return mx

        def f(l):
            dp = cnt = 0
            hull = collections.deque([(0, 0, 0)])
            for i in xrange(len(nums)):
                x = prefix[i+1]
                while len(hull) >= 2 and hull[0][0]*x+hull[0][1] >= hull[1][0]*x+hull[1][1]:
                    hull.popleft()
                dp, cnt = (hull[0][0]*x+hull[0][1])+(x*x+x)//2+l, hull[0][2]+1
                line = (-x, dp+(x*x-x)//2, cnt)
                while len(hull) >= 2 and not check(hull[-2], hull[-1], line):
                    hull.pop()
                hull.append(line)
            return dp, cnt

        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        mx = max_lambda()
        assert(f(mx+1)[1] == 1)
        l = binary_search(0, mx, lambda x: f(x)[1] <= k)
        return f(l)[0]-k*l


# Time:  O(n * k)
# Space: O(n)
import collections


# prefix sum, dp, convex hull trick
class Solution2(object):
    def minPartitionScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def check(l1, l2, l3):
            return (l2[1]-l1[1])*(l2[0]-l3[0]) < (l3[1]-l2[1])*(l1[0]-l2[0])

        INF = float("inf")
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        dp = [INF]*(len(nums)+1)
        for j in xrange(k):
            hull = collections.deque([(0, 0)])
            for i in xrange(j-1, len(nums)):
                x = prefix[i+1]
                while len(hull) >= 2 and hull[0][0]*x+hull[0][1] >= hull[1][0]*x+hull[1][1]:
                    hull.popleft()
                t = dp[i+1]
                dp[i+1] = hull[0][0]*x+hull[0][1]+(x*x+x)//2
                if t is INF:
                    continue
                line = (-x, t+(x*x-x)//2)
                while len(hull) >= 2 and not check(hull[-2], hull[-1], line):
                    hull.pop()
                hull.append(line)
            dp[j] = INF
        return dp[-1]
