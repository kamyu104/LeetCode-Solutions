# Time:  O(|V| + |E|)
# Space: O(|E|)

import collections


# bfs solution
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        in_degree = collections.defaultdict(set)
        out_degree = collections.defaultdict(set)
        for i, j in prerequisites:
            in_degree[i].add(j)
            out_degree[j].add(i)
        q = collections.deque([i for i in xrange(numCourses) if i not in in_degree])
        result = []
        while q:
            node = q.popleft()
            result.append(node)
            for i in out_degree[node]:
                in_degree[i].remove(node)
                if not in_degree[i]:
                    q.append(i)
                    del in_degree[i]
            del out_degree[node]
        return result if not in_degree and not out_degree else []


# Time:  O(|V| + |E|)
# Space: O(|E|)
# dfs solution
class Solution2(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        in_degree = collections.defaultdict(set)
        out_degree = collections.defaultdict(set)
        for i, j in prerequisites:
            in_degree[i].add(j)
            out_degree[j].add(i)
        stk = [i for i in xrange(numCourses) if i not in in_degree]
        result = []
        while stk:
            node = stk.pop()
            result.append(node)
            for i in out_degree[node]:
                in_degree[i].remove(node)
                if not in_degree[i]:
                    stk.append(i)
                    del in_degree[i]
            del out_degree[node]
        return result if not in_degree and not out_degree else []
