# Time:  O(max(x, max(forbidden)) + a + (b+a))
# Space: O(max(x, max(forbidden)) + a + (b+a))

class Solution(object):
    def minimumJumps(self, forbidden, a, b, x):
        """
        :type forbidden: List[int]
        :type a: int
        :type b: int
        :type x: int
        :rtype: int
        """
        max_f = max(forbidden)
        max_val = x+b if a >= b else max(x, max_f)+a+(b+a)  # a may be a non-periodic area, (a+b) is a periodic area which is divided by gcd(a, b) and all points are reachable
        lookup = set()      
        for pos in forbidden:
            lookup.add((pos, True))
            lookup.add((pos, False))
        result = 0
        q = [(0, True)]
        lookup.add((0, True))
        while q:
            new_q = []
            for pos, can_back in q:
                if pos == x:
                    return result
                if pos+a <= max_val and (pos+a, True) not in lookup:
                    lookup.add((pos+a, True))
                    new_q.append((pos+a, True))
                if not can_back:
                    continue
                if pos-b >= 0 and (pos-b, False) not in lookup:
                    lookup.add((pos-b, False))
                    new_q.append((pos-b, False))
            q = new_q
            result += 1
        return -1
