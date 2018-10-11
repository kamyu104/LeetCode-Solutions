# Time:  O(n!)
# Space: O(n)

class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        def canIWinHelper(maxChoosableInteger, desiredTotal, visited, lookup):
            if visited in lookup:
                return lookup[visited]

            mask = 1
            for i in xrange(maxChoosableInteger):
                if visited & mask == 0:
                    if i + 1 >= desiredTotal or \
                       not canIWinHelper(maxChoosableInteger, desiredTotal - (i + 1), visited | mask, lookup):
                        lookup[visited] = True
                        return True
                mask <<= 1
            lookup[visited] = False
            return False

        if (1 + maxChoosableInteger) * (maxChoosableInteger / 2) < desiredTotal:
            return False

        return canIWinHelper(maxChoosableInteger, desiredTotal, 0, {})

