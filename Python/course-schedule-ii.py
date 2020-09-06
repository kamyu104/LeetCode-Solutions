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
        indegree = collections.defaultdict(set)
        outdegree = collections.defaultdict(set)
        for i, j in prerequisites:
            indegree[i].add(j)
            outdegree[j].add(i)
        q = collections.deque([i for i in xrange(numCourses) if i not in indegree])
        result = []
        while q:
            node = q.popleft()
            result.append(node)
            for i in outdegree[node]:
                indegree[i].remove(node)
                if not indegree[i]:
                    q.append(i)
                    del indegree[i]
            del outdegree[node]
        return result if not indegree and not outdegree else []


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
        indegree = collections.defaultdict(set)
        outdegree = collections.defaultdict(set)
        for i, j in prerequisites:
            indegree[i].add(j)
            outdegree[j].add(i)
        stk = [i for i in xrange(numCourses) if i not in indegree]
        result = []
        while stk:
            node = stk.pop()
            result.append(node)
            for i in outdegree[node]:
                indegree[i].remove(node)
                if not indegree[i]:
                    stk.append(i)
                    del indegree[i]
            del outdegree[node]
        return result if not indegree and not outdegree else []
