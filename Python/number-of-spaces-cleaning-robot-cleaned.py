# Time:  O(m * n)
# Space: O(1)

class Solution(object):
    def numberOfCleanRooms(self, room):
        """
        :type room: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d = r = c = 0
        while not room[r][c]&(1<<(d+1)): 
            room[r][c] |= (1<<(d+1))
            dr, dc = DIRECTIONS[d]
            nr, nc = r+dr, c+dc
            if 0 <= nr < len(room) and 0 <= nc < len(room[0]) and not (room[nr][nc]&1):
                r, c = nr, nc
            else:
                d = (d+1)%4
        return sum(x>>1 != 0 for row in room for x in row)
