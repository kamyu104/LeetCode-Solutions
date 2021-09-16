# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findGameWinner(self, n):
        """
        :type n: int
        :rtype: bool
        """ 
        return n%6 != 1  # the cycle period is 6 observed from solution2, which could be proved by mathematical induction


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def findGameWinner(self, n):
        """
        :type n: int
        :rtype: bool
        """ 
        grundy = [0, 1]
        for i in xrange(2, n):
            grundy[i%2] = (grundy[(i-1)%2]+1)^(grundy[(i-2)%2]+1)  # colon principle, replace the branches by a non-branching stalk of length equal to their nim sum
        return grundy[(n-1)%2]
