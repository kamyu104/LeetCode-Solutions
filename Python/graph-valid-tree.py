# Time:  O(|V| + |E|)
# Space: O(|V|)

class Solution:
    # @param {integer} n
    # @param {integer[][]} edges
    # @return {boolean}
    def validTree(self, n, edges):
        if len(edges) != n - 1:
            return False

        nodes = {}
        for i in xrange(n):
            nodes[i] = [-1, []]
        for edge in edges:
            nodes[edge[0]][1].append(edge[1])
            nodes[edge[1]][1].append(edge[0])

        visited = {}
        q = collections.deque()
        q.append(0)
        while q:
            i = q.popleft()
            visited[i] = True
            for n in nodes[i][1]:
                if n != nodes[i][0]:
                    if n in visited:
                        return False
                    else:
                        visited[n] = True
                        nodes[n][0] = i
                        q.append(n)
        return True
