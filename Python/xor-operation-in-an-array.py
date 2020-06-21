# Time:  O(1)
# Space: O(1)

class Solution(object):
    def xorOperation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: int
        """
        def xorNums(n, start):
            def xorNumsBeginEven(n, start):
                assert(start%2 == 0)
                # 2*i ^ (2*i+1) = 1
                return ((n//2)%2)^((start+n-1) if n%2 else 0)

            return start^xorNumsBeginEven(n-1, start+1) if start%2 else xorNumsBeginEven(n, start)
        
        return int(n%2 and start%2) + 2*xorNums(n, start//2)


# Time:  O(n)
# Space: O(1)
import operator


class Solution2(object):
    def xorOperation(self, n, start):
        """
        :type n: int
        :type start: int
        :rtype: int
        """
        return reduce(operator.xor, (i for i in xrange(start, start+2*n, 2)))
