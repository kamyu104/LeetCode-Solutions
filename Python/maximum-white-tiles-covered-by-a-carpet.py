# Time:  O(nlogn)
# Space: O(1)

# sliding window
class Solution(object):
    def maximumWhiteTiles(self, tiles, carpetLen):
        """
        :type tiles: List[List[int]]
        :type carpetLen: int
        :rtype: int
        """
        tiles.sort()
        result = left = gap = 0
        for right in xrange(len(tiles)):
            if right-1 >= 0:
                gap += (tiles[right][0]-1)-tiles[right-1][1]
            result = max(result, min(tiles[right][1]-tiles[left][0]+1, carpetLen)-gap)
            while tiles[right][1]-tiles[left][0]+1 > carpetLen:
                left += 1
                gap -= (tiles[left][0]-1)-tiles[left-1][1]
                result = max(result, min(tiles[right][1]-tiles[left][0]+1, carpetLen)-gap)
        return result
