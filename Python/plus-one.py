# Time:  O(n)
# Space: O(1)
#
# Given a non-negative number represented as an array of digits, plus one to the number.
# 
# The digits are stored such that the most significant digit is at the head of the list.


class Solution:
    """
    :type digits: List[int]
    :rtype: List[int]
    """
    def plusOne(self, digits):
        carry = 1
        for i in reversed(xrange(len(digits))):
            digits[i] += carry
            carry = digits[i] / 10
            digits[i] %= 10
        
        if carry:
            digits = [1] + digits
        
        return digits

    def plusOne2(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits = [str(x) for x in digits]
        num = int(''.join(digits)) + 1
        return [int(x) for x in str(num)]

if __name__ == "__main__":
    print Solution().plusOne([9, 9, 9, 9])