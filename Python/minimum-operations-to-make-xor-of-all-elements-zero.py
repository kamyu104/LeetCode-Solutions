# Time:  O(n + r * d), r = max(nums), d = len(set(nums))
# Space: O(r + d)

# bfs
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = 0
        for x in nums:
            total ^= x
        if total == 0:
            return 0
        nums_set = set(nums)
        if len(nums_set) == 1:
            return -1
        dist = [-1]*(1<<max(nums).bit_length())
        dist[0] = 0
        q = [0]
        while q:
            new_q = []
            for u in q:
                if u == total:
                    return dist[u] if dist[u] != len(nums) else -1
                for v in nums_set:
                    if dist[u^v] != -1:
                        continue
                    dist[u^v] = dist[u]+1
                    q.append(u^v)
            q = new_q
        return -1
