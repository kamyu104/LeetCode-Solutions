# Time:  O(n * r), r = max(nums)
# Space: O(r)

# bitmasks, bfs
class Solution(object):
    def minRemovals(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def bfs():
            dist = {}
            dist[0] = 0
            q = [0]
            while q:
                new_q = []
                for k in q:
                    if k == target:
                        return dist[k]
                    for x in nums:
                        if k^x in dist:
                            continue
                        dist[k^x] = dist[k]+1
                        new_q.append(k^x)
                q = new_q
            return -1

        target ^= reduce(lambda accu, x: accu^x, nums, 0)
        return bfs()


# Time:  O(n * r), r = max(nums)
# Space: O(r)
# bitmasks, dp
class Solution2(object):
    def minRemovals(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = {}
        dp[0] = 0
        for x in nums:
            target ^= x
            new_dp = {k:v for k, v in dp.iteritems()}
            for k in dp.iterkeys():
                if k^x not in new_dp or new_dp[k^x] > dp[k]+1:
                    new_dp[k^x] = dp[k]+1
            dp = new_dp
        return dp[target] if target in dp else -1
