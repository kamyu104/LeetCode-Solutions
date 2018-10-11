# Time:  O(m * n)
# Space: O(m * n)

class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def dfs(image, r, c, newColor, color):
            if not (0 <= r < len(image) and \
                    0 <= c < len(image[0]) and \
                    image[r][c] == color):
                return

            image[r][c] = newColor
            for d in directions:
                dfs(image, r+d[0], c+d[1], newColor, color)

        color = image[sr][sc]
        if color == newColor: return image
        dfs(image, sr, sc, newColor, color)
        return image

