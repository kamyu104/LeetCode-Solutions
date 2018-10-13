# Time:  O(q + r)
# Space: O(q + r)


class Solution(object):
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """
        def dfs(graph, quiet, node, result):
            if result[node] is None:
                result[node] = node
                for nei in graph[node]:
                    smallest_person = dfs(graph, quiet, nei, result)
                    if quiet[smallest_person] < quiet[result[node]]:
                        result[node] = smallest_person
            return result[node]

        graph = [[] for _ in xrange(len(quiet))]
        for u, v in richer:
            graph[v].append(u)
        result = [None]*len(quiet)
        return map(lambda x: dfs(graph, quiet, x, result), xrange(len(quiet)))

