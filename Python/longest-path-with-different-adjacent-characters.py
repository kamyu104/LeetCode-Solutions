# Time:  O(n)
# Space: O(h)

# tree, dfs
class Solution(object):
    def longestPath(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """
        def iter_dfs(s, adj):
            result = 0
            stk = [(1, (0, [0]))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, ret = args
                    top2 = [0]*2
                    stk.append((4, (top2, ret)))
                    stk.append((2, (u, 0, top2, ret)))
                elif step == 2:
                    u, i, top2, ret = args
                    if i == len(adj[u]):
                        continue
                    ret2 = [0]
                    stk.append((3, (u, i, top2, ret2)))
                    stk.append((1, (adj[u][i], ret2))) 
                elif step == 3:
                    u, i, top2, ret2 = args
                    if s[adj[u][i]] != s[u]:
                        if ret2[0] > top2[0]:
                            top2[0], top2[1] = ret2[0], top2[0]
                        elif ret2[0] > top2[1]:
                            top2[1] = ret2[0]
                    stk.append((2, (u, i+1, top2, ret)))
                elif step == 4:
                    top2, ret = args
                    result = max(result, top2[0]+top2[1]+1)
                    ret[0] = top2[0]+1
            return result
    
        
        adj = [[] for _ in xrange(len(s))]
        for i in xrange(1, len(parent)):
            adj[parent[i]].append(i)
        return iter_dfs(s, adj)
    

# Time:  O(n)
# Space: O(h)
# tree, dfs
class Solution2(object):
    def longestPath(self, parent, s):
        """
        :type parent: List[int]
        :type s: str
        :rtype: int
        """
        def dfs(s, adj, u, result):
            top2 = [0]*2
            for v in adj[u]:
                l = dfs(s, adj, v, result)
                if s[v] == s[u]:
                    continue
                if l > top2[0]:
                    top2[0], top2[1] = l, top2[0]
                elif l > top2[1]:
                    top2[1] = l
            result[0] = max(result[0], top2[0]+top2[1]+1)
            return top2[0]+1
    
        
        adj = [[] for _ in xrange(len(s))]
        for i in xrange(1, len(parent)):
            adj[parent[i]].append(i)
        result = [0]
        dfs(s, adj, 0, result)
        return result[0]
    
