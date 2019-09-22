# Time:  O(n + e)
# Space: O(n + e)

import collections


class Topo(object):
    def __init__(self):
        self.__nodes = set()
        self.__in_degree = collections.defaultdict(set)
        self.__out_degree = collections.defaultdict(set)
        
    def add_node(self, node):
        self.__nodes.add(node)
    
    def add_edge(self, src, dst):
        self.add_node(src), self.add_node(dst)
        self.__in_degree[dst].add(src)
        self.__out_degree[src].add(dst)
    
    def sort(self):
        q = collections.deque()
        result = []
        for node in self.__nodes:
            if node not in self.__in_degree:
                q.append(node)
        while q:
            node = q.popleft()
            result.append(node)
            for nei in self.__out_degree[node]:
                self.__in_degree[nei].remove(node)
                if not self.__in_degree[nei]:
                    self.__in_degree.pop(nei)
                    q.append(nei)
        if len(result) < len(self.__nodes):
            return
        return result


class Solution(object):
    def sortItems(self, n, m, group, beforeItems):
        """
        :type n: int
        :type m: int
        :type group: List[int]
        :type beforeItems: List[List[int]]
        :rtype: List[int]
        """
        for i in xrange(n):
            if group[i] == -1:
                group[i] = m
                m += 1    
        global_group = Topo()
        for i in xrange(m):
            global_group.add_node(i)
        local_groups = collections.defaultdict(Topo)
        for i in xrange(n):
            local_groups[group[i]].add_node(i)
        for i in xrange(n):
            for j in beforeItems[i]:
                if group[i] == group[j]:
                    local_groups[group[i]].add_edge(j, i)
                else:
                    global_group.add_edge(group[j], group[i]);
        result = []
        global_order = global_group.sort()
        if global_order is None:
            return []
        for i in global_order:
            local_order = local_groups[i].sort();
            if local_order is None:
                return []
            for x in local_order:
                result.append(x)
        return result
