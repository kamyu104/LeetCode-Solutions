# Time:  O((m * n)^(4/3)), days = O((m * n)^(1/3))
# Space: O(m * n)

class Solution(object):
    def containVirus(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)]

        def dfs(grid, r, c, lookup, regions, frontiers, perimeters):
            if (r, c) in lookup:
                return
            lookup.add((r, c))
            regions[-1].add((r, c))
            for d in directions:
                nr, nc = r+d[0], c+d[1]
                if not (0 <= nr < len(grid) and \
                        0 <= nc < len(grid[r])):
                    continue
                if grid[nr][nc] == 1:
                    dfs(grid, nr, nc, lookup, regions, frontiers, perimeters)
                elif grid[nr][nc] == 0:
                    frontiers[-1].add((nr, nc))
                    perimeters[-1] += 1

        result = 0
        while True:
            lookup, regions, frontiers, perimeters = set(), [], [], []
            for r, row in enumerate(grid):
                for c, val in enumerate(row):
                    if val == 1 and (r, c) not in lookup:
                        regions.append(set())
                        frontiers.append(set())
                        perimeters.append(0)
                        dfs(grid, r, c, lookup, regions, frontiers, perimeters)

            if not regions: break

            triage_idx = frontiers.index(max(frontiers, key = len))
            for i, region in enumerate(regions):
                if i == triage_idx:
                    result += perimeters[i]
                    for r, c in region:
                        grid[r][c] = -1
                    continue
                for r, c in region:
                    for d in directions:
                        nr, nc = r+d[0], c+d[1]
                        if not (0 <= nr < len(grid) and \
                                0 <= nc < len(grid[r])):
                            continue
                        if grid[nr][nc] == 0:
                            grid[nr][nc] = 1

        return result

