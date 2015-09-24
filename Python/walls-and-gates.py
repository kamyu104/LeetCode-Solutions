# Time:  O(m * n)
# Space: O(m + n)

class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        q = [(i, j) for i, row in enumerate(rooms) for j, r in enumerate(row) if not r]
        for i, j in q:
            for I, J in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                if 0 <= I < len(rooms) and 0 <= J < len(rooms[0]) and rooms[I][J] == 2147483647:
                    rooms[I][J] = rooms[i][j] + 1
                    q += (I, J),
