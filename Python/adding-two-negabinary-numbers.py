# Time:  O(n)
# Space: O(n)

class Solution(object):
    def addNegabinary(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        result = []
        carry = 0
        while arr1 or arr2 or carry:
            if arr1:
                carry += arr1.pop()
            if arr2:
                carry += arr2.pop()
            result.append(carry & 1)
            carry = -(carry >> 1)
        while len(result) > 1 and result[-1] == 0:
            result.pop()
        result.reverse()
        return result
