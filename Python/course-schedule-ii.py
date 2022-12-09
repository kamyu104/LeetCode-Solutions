# Time:  O(|V| + |E|)
# Space: O(|E|)
import collections


# khan's algorithm
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        adj = collections.defaultdict(list)
        adj = collections.defaultdict(list)
        in_degree = collections.Counter()
        for u, v in prerequisites:
            in_degree[u] += 1
            adj[v].append(u)
        result = []
        q = [u for u in xrange(numCourses) if in_degree[u] == 0]
        while q:
            new_q = []
            for u in q:
                result.append(u)
                for v in adj[u]:
                    in_degree[v] -= 1
                    if in_degree[v] == 0:
                        new_q.append(v)
            q = new_q
        return result if len(result) == numCourses else []


# Time:  O(|V| + |E|)
# Space: O(|E|)
import collections


# dfs solution
class Solution2(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        WHITE, GRAY, BLACK = range(3)
        def dfs(u):
            if lookup[u] != WHITE:
                return lookup[u] == BLACK
            lookup[u] = GRAY
            if any(not dfs(v) for v in adj[u]):
                return False
            lookup[u] = BLACK
            result.append(u)  # should be postorder
            return True

        result = []
        adj = collections.defaultdict(list)
        for u, v in prerequisites:
            adj[v].append(u)
        lookup = collections.defaultdict(lambda:WHITE)
        for u in xrange(numCourses):
            if not dfs(u):
                return []
        result.reverse()
        return result


# Time:  O(|V| + |E|)
# Space: O(|E|)
import collections


# dfs solution
class Solution3(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        WHITE, GRAY, BLACK = range(3)
        def dfs(u):
            if lookup[u] != WHITE:
                return lookup[u] == BLACK
            lookup[u] = GRAY
            if any(not dfs(v) for v in adj[u]):
                return False
            lookup[u] = BLACK
            result.append(u)  # should be postorder
            return True

        adj = collections.defaultdict(list)
        for u, v in prerequisites:
            adj[u].append(v)
        result = []
        lookup = collections.defaultdict(lambda:WHITE)
        for u in xrange(numCourses):
            if not dfs(u):
                return []
        return result


# Time:  O(|V| + |E|)
# Space: O(|E|)
import collections


# bfs solution
class Solution4(object):
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
class Solution5(object):
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
