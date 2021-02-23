# Time:  O(50 * n) = O(n)
# Space: O(n)

import collections
import fractions


class Solution(object):
    def getCoprimes(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: List[int]
        """        
        def iter_dfs(nums, adj):
            result = [-1]*len(nums)
            path = collections.defaultdict(list)
            stk = [(1, (-1, 0, 0))]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    prev, node, depth = params
                    stk.append((4, (node,)))
                    stk.append((3, (prev, node, depth)))
                    stk.append((2, (node,)))
                elif step == 2:
                    node = params[0]
                    max_d = -1
                    for x in path.iterkeys():
                        if fractions.gcd(nums[node], x) != 1:
                            continue
                        if path[x][-1][1] > max_d:
                            max_d = path[x][-1][1]
                            result[node] = path[x][-1][0]
                elif step == 3:
                    prev, node, depth = params
                    path[nums[node]].append((node, depth))
                    for nei in adj[node]:
                        if nei == prev:
                            continue
                        stk.append((1, (node, nei, depth+1)))
                elif step == 4:
                    node = params[0]
                    path[nums[node]].pop()
                    if not path[nums[node]]:
                        path.pop(nums[node])
            return result

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs(nums, adj)


# Time:  O(50 * n) = O(n)
# Space: O(n)
import collections
import fractions


class Solution2(object):
    def getCoprimes(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: List[int]
        """        
        def dfs(nums, adj, prev, node, depth, path, result):
            max_d = -1
            for x in path.iterkeys():
                if fractions.gcd(nums[node], x) != 1:
                    continue
                if path[x][-1][1] > max_d:
                    max_d = path[x][-1][1]
                    result[node] = path[x][-1][0]
            path[nums[node]].append((node, depth))
            for nei in adj[node]:
                if nei == prev:
                    continue
                dfs(nums, adj, node, nei, depth+1, path, result)
            path[nums[node]].pop()
            if not path[nums[node]]:
                path.pop(nums[node])

        adj = collections.defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [-1]*len(nums)
        path = collections.defaultdict(list)
        dfs(nums, adj, -1, 0, 0, path, result)
        return result
