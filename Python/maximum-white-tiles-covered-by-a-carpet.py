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


# Time:  O(nlogn)
# Space: O(n)
# prefix sum, binary search
class Solution2(object):
    def maximumWhiteTiles(self, tiles, carpetLen):
        """
        :type tiles: List[List[int]]
        :type carpetLen: int
        :rtype: int
        """
        tiles.sort()
        prefix = [0]*(len(tiles)+1)
        for i, (l, r) in enumerate(tiles):
            prefix[i+1] = prefix[i]+(r-l+1)
        result = 0
        for i, (l, _) in enumerate(tiles):
            r = l+carpetLen-1
            j = bisect.bisect_right(tiles, [r+1])
            extra = max(tiles[j-1][1]-r, 0)
            result = max(result, (prefix[j]-prefix[i])-extra)
        return result
