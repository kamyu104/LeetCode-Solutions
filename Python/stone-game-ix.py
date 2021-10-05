# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        count = collections.Counter(x%3 for x in stones)
        if count[0]%2 == 0:
            # iff both counts are not zero, then alice takes the least one at first, the remains are deterministic for bob to lose:
            # - assumed count[1] is the least one:
            #   1(,1,2)*,2,(,2)* => bob loses
            #            ^
            # - assumed count[2] is the least one:
            #   2(,2,1)*,1,(,1)* => bob loses
            #            ^
            return count[1] and count[2]
        # iff abs(count[1] - count[2]) >= 3, then alice takes the most one at first, the remains are deterministic for bob to lose:
        # - assumed count[1] is the most one
        #   1(,1,2)*,0,1(,2,1)*,1,(,1)* => bob loses
        #                       ^
        #   1(,1,2)*,1,0,1,(,1)* => bob loses
        #                ^
        # - assumed count[2] is the most one
        #   2(,2,1)*,0,2(,1,2)*,2,(,2)* => bob loses
        #                       ^
        #   2(,2,1)*,2,0,2,(,2)* => bob loses
        #                ^
        return abs(count[1]-count[2]) >= 3  
