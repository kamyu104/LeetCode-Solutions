# Time:  O(n)
# Space: O(1)

class Solution(object):
    def decode(self, encoded):
        """
        :type encoded: List[int]
        :rtype: List[int]
        """
        curr = 0
        for i in xrange(1, (len(encoded)+1) + 1):
            curr ^= i
            if i < len(encoded) and i%2 == 1:
                curr ^= encoded[i]
        result = [curr]
        for x in encoded:
            result.append(result[-1]^x)
        return result
