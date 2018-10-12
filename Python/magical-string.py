# Time:  O(n)
# Space: O(logn)

import itertools


class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        def gen():  # see figure 1 on page 3 of http://www.emis.ams.org/journals/JIS/VOL15/Nilsson/nilsson5.pdf
            for c in 1, 2, 2:
                yield c
            for i, c in enumerate(gen()):
                if i > 1:
                    for _ in xrange(c):
                        yield i % 2 + 1

        return sum(c & 1 for c in itertools.islice(gen(), n))

