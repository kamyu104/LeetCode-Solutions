# Time:  O(n)
# Space: O(n)

# iterative dfs
class Solution(object):
    def placedCoins(self, edges, cost):
        """
        :type edges: List[List[int]]
        :type cost: List[int]
        :rtype: List[int]
        """
        def iter_dfs():
            result = [0]*len(cost)
            stk = [(1, (0, -1, [cost[0]]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    stk.append((4, (u, ret)))
                    stk.append((2, (u, p, 0, ret)))
                elif step == 2:
                    u, p, i, ret = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, p, i+1, ret)))
                    if v == p:
                        continue
                    new_ret = [cost[v]]
                    stk.append((3, (new_ret, ret)))
                    stk.append((1, (v, u, new_ret)))
                elif step == 3:
                    new_ret, ret = args
                    ret.extend(new_ret)
                    ret.sort()
                    if len(ret) > 5:
                        ret = ret[:2]+ret[-3:]
                elif step == 4:
                    u, ret = args
                    result[u] = 1 if len(ret) < 3 else max(ret[0]*ret[1]*ret[-1], ret[-3]*ret[-2]*ret[-1], 0)
            return result
                
        adj = [[] for _ in xrange(len(cost))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(n)
# Space: O(n)
# dfs
class Solution2(object):
    def placedCoins(self, edges, cost):
        """
        :type edges: List[List[int]]
        :type cost: List[int]
        :rtype: List[int]
        """
        def dfs(u, p):
            arr = [cost[u]]
            for v in adj[u]:
                if v == p:
                    continue
                arr.extend(dfs(v, u))
                arr.sort()
                if len(arr) > 5:
                    arr = arr[:2]+arr[-3:]
            result[u] = 1 if len(arr) < 3 else max(arr[0]*arr[1]*arr[-1], arr[-3]*arr[-2]*arr[-1], 0)
            return arr
                
        adj = [[] for _ in xrange(len(cost))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [0]*len(cost)
        dfs(0, -1)
        return result
