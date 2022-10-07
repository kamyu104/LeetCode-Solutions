# Time:  O(|V| + |E|)
# Space: O(|V|)

class Solution(object):
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        WHITE, GRAY, BLACK = range(3)

        def dfs(graph, node, lookup):
            if lookup[node] != WHITE:
                return lookup[node] == BLACK
            lookup[node] = GRAY
            if any(not dfs(graph, child, lookup) for child in graph[node]):
                return False
            lookup[node] = BLACK
            return True

        lookup = [WHITE]*len(graph)
        return filter(lambda node: dfs(graph, node, lookup), xrange(len(graph)))
