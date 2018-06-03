# Time:  O(n * 2^n)
# Space: O(n * 2^n)

# An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1)
# is given as graph.
#
# graph.length = N, and j != i is in the list graph[i] exactly once,
# if and only if nodes i and j are connected.
#
# Return the length of the shortest path that visits every node.
# You may start and stop at any node, you may revisit nodes multiple times,
# and you may reuse edges.
#
# Example 1:
#
# Input: [[1,2,3],[0],[0],[0]]
# Output: 4
# Explanation: One possible path is [1,0,2,0,3]
# Example 2:
#
# Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
# Output: 4
# Explanation: One possible path is [0,1,4,2,3]
#
# Note:
# - 1 <= graph.length <= 12
# - 0 <= graph[i].length < graph.length

import collections

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        dp = [[float("inf")]*(len(graph))
              for _ in xrange(1 << len(graph))]
        q = collections.deque()
        for i in xrange(len(graph)):
            dp[1 << i][i] = 0
            q.append((1 << i, i))
        while q:
            state, node = q.popleft()
            steps = dp[state][node]
            for nei in graph[node]:
                new_state = state | (1 << nei)
                if dp[new_state][nei] == float("inf"):
                    dp[new_state][nei] = steps+1
                    q.append((new_state, nei))
        return min(dp[-1])
