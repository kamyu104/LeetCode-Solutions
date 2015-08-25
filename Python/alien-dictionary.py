# Time:  O(|V|+|E|) = O(26 + 26^2) = O(1)
# Space: O(|V|+|E|) = O(26 + 26^2) = O(1)

class Solution(object):
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        # Find ancestors of each node by DFS.
        nodes, ancestors = sets.Set(), {}
        for i in xrange(len(words)):
            for c in words[i]:
                nodes.add(c)
        for node in nodes:
            ancestors[node] = []
        for i in xrange(1, len(words)):
            self.findEdges(words[i - 1], words[i], ancestors)

        # Output topological order by DFS.
        result = []
        visited = {}
        for node in nodes:
            if self.topSortDFS(node, node, ancestors, visited, result):
                return ""
        
        return "".join(result)


    # Construct the graph.
    def findEdges(self, word1, word2, ancestors):
        min_len = min(len(word1), len(word2))
        for i in xrange(min_len):
            if word1[i] != word2[i]:
                ancestors[word2[i]].append(word1[i])
                break


    # Topological sort, return whether there is a cycle.
    def topSortDFS(self, root, node, ancestors, visited, result):
        if node not in visited:
            visited[node] = root
            for ancestor in ancestors[node]:
                if self.topSortDFS(root, ancestor, ancestors, visited, result):
                    return True
            result.append(node)
        elif visited[node] == root:
            # Visited from the same root in the DFS path.
            # So it is cyclic.
            return True
        return False
