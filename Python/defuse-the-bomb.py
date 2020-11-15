# Time:  O(n)
# Space: O(1)

class Solution(object):
    def decrypt(self, code, k):
        """
        :type code: List[int]
        :type k: int
        :rtype: List[int]
        """
        result = [0]*len(code)
        if k == 0:
            return result
        left, right = 1, k
        if k < 0:
            k = -k
            left, right = len(code)-k, len(code)-1
        total = sum(code[i] for i in xrange(left, right+1))
        for i in xrange(len(code)):
            result[i] = total
            total -= code[left%len(code)]
            total += code[(right+1)%len(code)]
            left += 1
            right += 1
        return result
