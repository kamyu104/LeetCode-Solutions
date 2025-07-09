# Time:  O(logtx + logty)
# Space: O(1)

# backward simulation
class Solution(object):
    def minMoves(self, sx, sy, tx, ty):
        """
        :type sx: int
        :type sy: int
        :type tx: int
        :type ty: int
        :rtype: int
        """
        result = 0
        while (sx, sy) != (tx, ty):
            if not (sx <= tx and sy <= ty):
                return -1
            if tx < ty:
                if tx > ty-tx:
                    ty -= tx
                else:
                    if ty%2:
                        return -1
                    ty -= ty//2
            elif tx > ty:
                if ty > tx-ty:
                    tx -= ty
                else:
                    if tx%2:
                        return -1
                    tx -= tx//2
            else:
                if sx == 0:
                    tx -= ty
                elif sy == 0:
                    ty -= tx
                else:
                    return -1
            result += 1
        return result
