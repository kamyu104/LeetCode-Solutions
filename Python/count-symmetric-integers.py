# Time:  O(rlogr)
# Space: O(r)

# brute force, memoization
MAX_R = 10**4
LOOKUP = [-1]*MAX_R
class Solution(object):
    def countSymmetricIntegers(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        def check(x):
            if LOOKUP[x-1] == -1:
                digits = map(int, str(x))
                if len(digits)%2:
                    LOOKUP[x-1] = 0
                else:
                    LOOKUP[x-1] = int(sum(digits[i] for i in xrange(len(digits)//2)) == sum(digits[i] for i in xrange(len(digits)//2, len(digits))))
            return LOOKUP[x-1]

        return sum(check(x) for x in xrange(low, high+1))
