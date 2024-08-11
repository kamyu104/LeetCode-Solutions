# Time:  O(n)
# Space: O(h)

# iterative dfs
class Solution(object):
    def countGoodNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def iter_dfs():
            result = 0
            stk = [(1, (0, -1, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    l, valid = [0], [True]
                    stk.append((4, (ret, valid)))
                    stk.append((2, (u, p, 0, ret, l, valid)))
                elif step == 2:
                    u, p, i, ret, l, valid = args
                    if i == len(adj[u]):
                        continue
                    stk.append((2, (u, p, i+1, ret, l, valid)))
                    v = adj[u][i]
                    if v == p:
                        continue
                    new_ret = [0]
                    stk.append((3, (new_ret, ret, l, valid)))
                    stk.append((1, (v, u, new_ret)))
                elif step == 3:
                    new_ret, ret, l, valid = args
                    ret[0] += new_ret[0]
                    l[0] += 1
                    if new_ret[0]*l[0] != ret[0]:
                        valid[0] = False
                elif step == 4:
                    ret, valid = args
                    if valid[0]:
                        result += 1
                    ret[0] += 1
            return result

        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        return iter_dfs()


# Time:  O(n)
# Space: O(h)
# dfs
class Solution2(object):
    def countGoodNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        def dfs(u, p):
            total = l = 0
            valid = True
            for v in adj[u]:
                if v == p:
                    continue
                cnt = dfs(v, u)
                total += cnt
                l += 1
                if l*cnt != total:
                    valid = False
            if valid:
                result[0] += 1
            return total+1
        
        adj = [[] for _ in xrange(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [0]
        dfs(0, -1)
        return result[0]
