# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findGameWinner(self, n):
        """
        :type n: int
        :rtype: bool
        """ 
        # a pattern appears every 6 grundy numbers in binary forms:
        # 0000, (XXXX+1)01, (XXXX+1)11, (((XXXX+1))^((XXXX+1)+1))10, (XXXX+1)11, (XXXX+1)11
        return n%6 != 1


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
