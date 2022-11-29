# Time:  O(nlogr), r is sum(values)
# Space: O(n)

# iterative dfs, trie, greedy
class Trie(object):
    def __init__(self, bit_length):
        self.__root = {}
        self.__bit_length = bit_length
        
    def insert(self, num):
        node = self.__root
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if curr not in node:
                node[curr] = {}
            node = node[curr]
                
    def query(self, num):
        if not self.__root: 
            return -1
        node, result = self.__root, 0
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if 1^curr in node:
                node = node[1^curr]
                result |= 1<<i
            else:
                node = node[curr]
        return result


class Solution(object):
    def maxXor(self, n, edges, values):
        """
        :type n: int
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        def iter_dfs():
            lookup = [0]*len(values)
            stk = [(1, 0, -1)]
            while stk:
                step, u, p = stk.pop()
                if step == 1:
                    stk.append((2, u, p))
                    for v in adj[u]:
                        if v == p:
                            continue
                        stk.append((1, v, u))
                elif step == 2:
                    lookup[u] = values[u]+sum(lookup[v] for v in adj[u] if v != p)
            return lookup

        def iter_dfs2():
            trie = Trie(lookup[0].bit_length())
            result = [0]
            stk = [(1, (0, -1, result))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, p, ret = args
                    ret[0] = max(trie.query(lookup[u]), 0)
                    stk.append((3, (u,)))
                    for v in adj[u]:
                        if v == p:
                            continue
                        new_ret = [0]
                        stk.append((2, (new_ret, ret)))
                        stk.append((1, (v, u, new_ret)))
                elif step == 2:
                    new_ret, ret = args
                    ret[0] = max(ret[0], new_ret[0])
                elif step == 3:
                    u = args[0]
                    trie.insert(lookup[u])
            return result[0]
        
        adj = [[] for _ in xrange(len(values))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = iter_dfs()
        return iter_dfs2()


# Time:  O(nlogr), r is sum(values)
# Space: O(n)
# dfs, trie, greedy
class Trie(object):
    def __init__(self, bit_length):
        self.__root = {}
        self.__bit_length = bit_length
        
    def insert(self, num):
        node = self.__root
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if curr not in node:
                node[curr] = {}
            node = node[curr]
                
    def query(self, num):
        if not self.__root: 
            return -1
        node, result = self.__root, 0
        for i in reversed(xrange(self.__bit_length)):
            curr = (num>>i) & 1
            if 1^curr in node:
                node = node[1^curr]
                result |= 1<<i
            else:
                node = node[curr]
        return result


class Solution2(object):
    def maxXor(self, n, edges, values):
        """
        :type n: int
        :type edges: List[List[int]]
        :type values: List[int]
        :rtype: int
        """
        def dfs(u, p):
            lookup[u] = values[u]+sum(dfs(v, u) for v in adj[u] if v != p)
            return lookup[u]

        def dfs2(u, p):
            result = max(trie.query(lookup[u]), 0)
            for v in adj[u]:
                if v == p:
                    continue
                result = max(result, dfs2(v, u))
            trie.insert(lookup[u])
            return result
        
        adj = [[] for _ in xrange(len(values))]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        lookup = [0]*len(values)
        dfs(0, -1)
        trie = Trie(lookup[0].bit_length())
        return dfs2(0, -1)
