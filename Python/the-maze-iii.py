# Time:  O(max(r, c) * wlogw)
# Space: O(w^2)

class Solution(object):
    def findShortestWay(self, maze, ball, hole):
        """
        :type maze: List[List[int]]
        :type ball: List[int]
        :type hole: List[int]
        :rtype: str
        """
        ball, hole = tuple(ball), tuple(hole)
        dirs = {'u' : (-1, 0), 'r' : (0, 1), 'l' : (0, -1), 'd': (1, 0)}
        
        def neighbors(maze, node):
            for dir, vec in dirs.iteritems():
                cur_node, dist = list(node), 0
                while 0 <= cur_node[0]+vec[0] < len(maze) and \
                      0 <= cur_node[1]+vec[1] < len(maze[0]) and \
                      not maze[cur_node[0]+vec[0]][cur_node[1]+vec[1]]:
                    cur_node[0] += vec[0]
                    cur_node[1] += vec[1]
                    dist += 1
                    if tuple(cur_node) == hole:
                        break
                yield tuple(cur_node), dir, dist
        
        heap = [(0, '', ball)]
        visited = set()
        while heap:
            dist, path, node = heapq.heappop(heap)
            if node in visited: continue
            if node == hole: return path
            visited.add(node)
            for neighbor, dir, neighbor_dist in neighbors(maze, node):
                heapq.heappush(heap, (dist+neighbor_dist, path+dir, neighbor))
            
        return "impossible"
