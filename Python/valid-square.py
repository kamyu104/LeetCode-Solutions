# Time:  O(1)
# Space: O(1)

class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        def dist(p1, p2):
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

        lookup = set([dist(p1, p2), dist(p1, p3),\
                      dist(p1, p4), dist(p2, p3),\
                      dist(p2, p4), dist(p3, p4)])
        return 0 not in lookup and len(lookup) == 2

