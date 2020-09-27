# Time:  O((n + r) * 2^r)
# Space: O(n + r)

import itertools


# early return solution
class Solution(object):
    def maximumRequests(self, n, requests):
        """
        :type n: int
        :type requests: List[List[int]]
        :rtype: int
        """
        for k in reversed(xrange(1, len(requests)+1)):
            for c in itertools.combinations(xrange(len(requests)), k):
                change = [0]*n
                for i in c:
                    change[requests[i][0]] -= 1
                    change[requests[i][1]] += 1
                if all(c == 0 for c in change):
                    return k  # early return
        return 0
    

# Time:  O((n + r) * 2^r)
# Space: O(n + r)
# full search solution (much slower)
class Solution2(object):
    def maximumRequests(self, n, requests):
        """
        :type n: int
        :type requests: List[List[int]]
        :rtype: int
        """
        def evaluate(n, requests, mask):
            change = [0]*n
            base, count = 1, 0
            for i in xrange(len(requests)):
                if base & mask:
                    change[requests[i][0]] -= 1
                    change[requests[i][1]] += 1
                    count += 1
                base <<= 1
            return count if all(c == 0 for c in change) else 0

        return max(evaluate(n, requests, i) for i in xrange(1 << len(requests)))
