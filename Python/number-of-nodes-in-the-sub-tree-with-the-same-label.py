# Time:  O(n)
# Space: O(h)

class Solution(object):
    def countSubTrees(self, n, edges, labels):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :rtype: List[int]
        """
        def iter_dfs(labels, adj, node, parent, result):
            stk = [(1, (node, parent, [0]*26))]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, parent, ret = params
                    stk.append((4, (node, ret)))
                    stk.append((2, (node, parent, reversed(adj[node]), ret)))
                elif step == 2:
                    node, parent, it, ret = params
                    child = next(it, None)
                    if not child or child == parent:
                        continue
                    ret2 = [0]*26
                    stk.append((2, (node, parent, it, ret)))
                    stk.append((3, (ret2, ret)))
                    stk.append((1, (child, node, ret2)))
                elif step == 3:
                    ret2, ret = params
                    for k in xrange(len(ret2)):
                        ret[k] += ret2[k]
                else:
                    node, ret = params
                    ret[ord(labels[node]) - ord('a')] += 1
                    result[node] += ret[ord(labels[node]) - ord('a')]
        
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [0]*n
        iter_dfs(labels, adj, 0, -1, result)
        return result


# Time:  O(n)
# Space: O(h)
import collections


class Solution2(object):
    def countSubTrees(self, n, edges, labels):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :rtype: List[int]
        """
        def dfs(labels, adj, node, parent, result):
            count = [0]*26
            for child in adj[node]:
                if child == parent:
                    continue
                new_count = dfs(labels, adj, child, node, result)
                for k in xrange(len(new_count)):
                    count[k] += new_count[k]
            count[ord(labels[node]) - ord('a')] += 1
            result[node] = count[ord(labels[node]) - ord('a')]
            return count
        
        adj = [[] for _ in xrange(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        result = [0]*n
        dfs(labels, adj, 0, -1, result)
        return result
