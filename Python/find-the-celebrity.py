# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        candidate = 0
        # Find the candidate.
        for i in xrange(1, n):
            if knows(candidate, i):  # noqa
                candidate = i        # All candidates < i are not celebrity candidates.
        # Verify the candidate.
        for i in xrange(n):
            candidate_knows_i = knows(candidate, i) # noqa
            i_knows_candidate = knows(i, candidate) # noqa
            if i != candidate and (candidate_knows_i or
                                   not i_knows_candidate):
                return -1
        return candidate

