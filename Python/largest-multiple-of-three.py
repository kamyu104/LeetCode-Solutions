# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def largestMultipleOfThree(self, digits):
        """
        :type digits: List[int]
        :rtype: str
        """
        lookup = {0: [],
                  1: [(1,), (4,), (7,), (2, 2), (2, 5), (5, 5), (2, 8), (5, 8), (8, 8)],
                  2: [(2,), (5,), (8,), (1, 1), (1, 4), (4, 4), (1, 7), (4, 7), (7, 7)]}
        count = collections.Counter(digits)
        for candidate in lookup[sum(digits)%3]:
            if all(count[d] >= candidate.count(d) for d in candidate):
                for d in candidate:
                    count[d] -= 1
                break
        result = "".join(str(d)*count[d] for d in reversed(xrange(10)))
        if result and result[0] == '0':
            return "0"
        return result
    

# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def largestMultipleOfThree(self, digits):
        """
        :type digits: List[int]
        :rtype: str
        """
        def candidates_gen(r):
            if r == 0:
                return
            for i in xrange(10):
                yield [i]
            for i in xrange(10):
                for j in xrange(i+1):
                    yield [i, j]

        count, total = collections.Counter(digits), sum(digits)
        for deletes in candidates_gen(total%3):
            if sum(deletes)%3 == total%3 and \
               all(count[d] >= deletes.count(d) for d in deletes):
                for d in deletes:
                    count[d] -= 1
                break
        result = "".join(str(d)*count[d] for d in reversed(xrange(10)))
        if result and result[0] == '0':
            return "0"
        return result
