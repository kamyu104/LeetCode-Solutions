# Time:  O(m * n)
# Space: O(m + n)
#
# Given two numbers represented as strings, return multiplication of the numbers as a string.
# 
# Note: The numbers can be arbitrarily large and are non-negative.
#

class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
        num1, num2 = num1[::-1], num2[::-1]
        result = [0 for i in xrange(len(num1) + len(num2))]
        for i in xrange(len(num1)):
            for j in xrange(len(num2)):
                result[i + j] += int(num1[i]) * int(num2[j])
                
        carry, num3 = 0, []
        for digit in result:
            sum = carry + digit
            carry = sum / 10
            num3.insert(0, str(sum % 10))
            
        while len(num3) > 1 and num3[0] == "0":
            del num3[0]
            
        return ''.join(num3)

if __name__ == "__main__":
    print Solution().multiply("123", "1000")