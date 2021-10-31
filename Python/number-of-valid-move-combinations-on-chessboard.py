# Time:  O(n^p) = O(1), n is the max number of possible moves for each piece, and n is at most 29
#                     , p is the number of pieces, and p is at most 4
# Space: O(1)

class Solution(object):
    def countCombinations(self, pieces, positions):
        """
        :type pieces: List[str]
        :type positions: List[List[int]]
        :rtype: int
        """
        directions = {"rook": [(0, 1), (1, 0), (0, -1), (-1, 0)],
                      "bishop": [(1, 1), (1, -1), (-1, 1), (-1, -1)],
                      "queen" : [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]}
        all_mask = 2**7-1  # at most 7 seconds in 8x8 board
        def backtracking(pieces, positions, i, lookup):
            if i == len(pieces):
                return 1
            result = 0
            r, c = positions[i]
            r, c = r-1, c-1
            mask = all_mask
            if not (lookup[r][c]&mask):
                lookup[r][c] += mask  # stopped at (r, c)
                result += backtracking(pieces, positions, i+1, lookup)
                lookup[r][c] -= mask          
            for dr, dc in directions[pieces[i]]:
                bit, nr, nc = 1, r+dr, c+dc
                mask = all_mask  # (mask&bit == 1): (log2(bit)+1)th second is occupied
                while 0 <= nr < 8 and 0 <= nc < 8 and not (lookup[nr][nc]&bit):
                    lookup[nr][nc] += bit
                    mask -= bit
                    if not (lookup[nr][nc]&mask):  # stopped at (nr, nc)
                        lookup[nr][nc] += mask
                        result += backtracking(pieces, positions, i+1, lookup)
                        lookup[nr][nc] -= mask
                    bit, nr, nc = bit<<1, nr+dr, nc+dc
                while bit>>1:
                    bit, nr, nc = bit>>1, nr-dr, nc-dc
                    lookup[nr][nc] -= bit
            return result

        return backtracking(pieces, positions, 0, [[0]*8 for _ in range(8)])
