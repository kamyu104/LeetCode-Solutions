# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        str_N = str(N)
        set_D = set(D)
        result = sum(len(D)**i for i in xrange(1, len(str_N)))
        i = 0
        while i < len(str_N):
            result += sum(c < str_N[i] for c in D) * (len(D)**(len(str_N)-i-1))
            if str_N[i] not in set_D:
                break
            i += 1
        return result + int(i == len(str_N))

