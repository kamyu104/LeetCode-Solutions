# Time:  O(max(r, c) * wlogw)
# Space: O(w^2)

class Solution(object):
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: int
        """
        start, destination = tuple(start), tuple(destination)
        
        def neighbors(maze, node):
            for dir in [(-1, 0), (0, 1), (0, -1), (1, 0)]:
                cur_node, dist = list(node), 0
                while 0 <= cur_node[0]+dir[0] < len(maze) and \
                      0 <= cur_node[1]+dir[1] < len(maze[0]) and \
                      not maze[cur_node[0]+dir[0]][cur_node[1]+dir[1]]:
                    cur_node[0] += dir[0]
                    cur_node[1] += dir[1]
                    dist += 1
                yield dist, tuple(cur_node)

        result = None
        heap = [(0, start)]
        visited = set()
        while heap:
            dist, node = heapq.heappop(heap)
            if node in visited: continue
            if node == destination:
                result = min(result, dist) if result else dist
            visited.add(node)
            for neighbor_dist, neighbor in neighbors(maze, node):
                heapq.heappush(heap, (dist+neighbor_dist, neighbor))
            
        return result if result else -1
