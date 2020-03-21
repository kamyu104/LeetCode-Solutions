# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        lookup = collections.defaultdict(lambda: [False]*3)
        for r, c in reservedSeats:
            if 2 <= c <= 5:
                lookup[r][0] = True
            if 4 <= c <= 7:
                lookup[r][1] = True
            if 6 <= c <= 9:
                lookup[r][2] = True
        result = 2*n
        for a, b, c in lookup.itervalues():
            if not a and not c:
                continue
            if not a or not b or not c:
                result -= 1
                continue
            result -= 2
        return result


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        reservedSeats.sort()
        result, i = 2*n, 0
        while i < len(reservedSeats):
            reserved = [False]*3
            curr = reservedSeats[i][0]
            while i < len(reservedSeats) and reservedSeats[i][0] == curr:
                _, c  = reservedSeats[i]
                if 2 <= c <= 5:
                    reserved[0] = True
                if 4 <= c <= 7:
                    reserved[1] = True
                if 6 <= c <= 9:
                    reserved[2] = True
                i += 1
            if not reserved[0] and not reserved[2]:
                continue
            if not all(reserved):
                result -= 1
                continue
            result -= 2
        return result
