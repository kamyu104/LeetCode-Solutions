# Time:  O(|V| + |E|)
# Space: O(|V| + |E|)

# BFS solution. Same complexity but faster version.
class Solution:
    # @param {integer} n
    # @param {integer[][]} edges
    # @return {boolean}
    def validTree(self, n, edges):
        if len(edges) != n - 1:  # Check number of edges.
            return False
        elif n == 1:
            return True

        # A structure to track each node's [visited_from, neighbors]
        visited_from = [-1] * n
        neighbors = collections.defaultdict(list)
        for u, v in edges:
            neighbors[u].append(v)
            neighbors[v].append(u)
        
        if len(neighbors) != n:  # Check number of nodes.
            return False

        # BFS to check whether the graph is valid tree.
        visited = {}
        q = collections.deque([0])
        while q:
            i = q.popleft()
            visited[i] = True
            for node in neighbors[i]:
                if node != visited_from[i]:
                    if node in visited:
                        return False
                    else:
                        visited[node] = True
                        visited_from[node] = i
                        q.append(node)
        return len(visited) == n


# Time:  O(|V| + |E|)
# Space: O(|V| + |E|)
# BFS solution.
class Solution2:
    # @param {integer} n
    # @param {integer[][]} edges
    # @return {boolean}
    def validTree(self, n, edges):
        # A structure to track each node's [visited_from, neighbors]
        visited_from = [-1] * n
        neighbors = collections.defaultdict(list)
        for u, v in edges:
            neighbors[u].append(v)
            neighbors[v].append(u)

        # BFS to check whether the graph is valid tree.
        visited = {}
        q = collections.deque([0])
        while q:
            i = q.popleft()
            visited[i] = True
            for node in neighbors[i]:
                if node != visited_from[i]:
                    if node in visited:
                        return False
                    else:
                        visited[node] = True
                        visited_from[node] = i
                        q.append(node)
        return len(visited) == n
