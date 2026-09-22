# Time:  O(n + r * d), r = max(nums), d = len(set(nums))
# Space: O(r + d)

# bi-bfs
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def bi_bfs(start, target):
            left, right = {start}, {target}
            lookup = set()
            steps = 0
            while left:
                if len(left) > len(right):
                    left, right = right, left
                for x in left:
                    lookup.add(x)
                new_left = set()
                for x in left:
                    if x in right:
                        return steps
                    for v in nums_set:
                        nx = x^v
                        if nx in lookup:
                            continue
                        new_left.add(nx)
                left = new_left
                steps += 1
            return -1

        total = 0
        for x in nums:
            total ^= x
        if total == 0:
            return 0
        nums_set = set(nums)
        if len(nums_set) == 1:
            return -1
        steps = bi_bfs(0, total)
        return steps if steps != len(nums) else -1


# Time:  O(n + r * d), r = max(nums), d = len(set(nums))
# Space: O(r + d)
# bfs
class Solution2(object):
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
