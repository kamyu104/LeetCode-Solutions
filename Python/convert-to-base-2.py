# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def baseNeg2(self, N):
        """
        :type N: int
        :rtype: str
        """
        result = []
        while N:
            result.append(str(-N & 1))  # N % -2
            N = -(N >> 1)  # N //= -2
        result.reverse()
        return "".join(result) if result else "0"


# Time:  O(logn)
# Space: O(1)
class Solution2(object):
    def baseNeg2(self, N):
        """
        :type N: int
        :rtype: str
        """
        BASE = -2
        result = []
        while N:
            N, r = divmod(N, BASE)
            if r < 0:
                r -= BASE
                N += 1
            result.append(str(r))
        result.reverse()
        return "".join(result) if result else "0"
