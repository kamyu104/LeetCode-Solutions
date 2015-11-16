# Time:  O(klog*k) ~= O(k), k is the length of the positions
# Space: O(k)

class Solution(object):
    def numIslands2(self, m, n, positions):
        """
        :type m: int
        :type n: int
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        def node_id(node, n):
            return node[0] * n + node[1]

        def find_set(x):
           if set[x] != x:
               set[x] = find_set(set[x])  # path compression.
           return set[x]

        def union_set(x, y):
            x_root, y_root = find_set(x), find_set(y)
            set[min(x_root, y_root)] = max(x_root, y_root)
  
        numbers = []
        number = 0
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        set = {}
        for position in positions:
            node = (position[0], position[1])
            set[node_id(node, n)] = node_id(node, n)
            number += 1

            for d in directions:
                neighbor = (position[0] + d[0], position[1] + d[1])
                if 0 <= neighbor[0] < m and 0 <= neighbor[1] < n and \
                   node_id(neighbor, n) in set:
                   if find_set(node_id(node, n)) != find_set(node_id(neighbor, n)):
                       # Merge different islands, amortised time: O(log*k) ~= O(1)
                       union_set(node_id(node, n), node_id(neighbor, n))
                       number -= 1
            numbers.append(number)

        return numbers
