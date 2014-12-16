# Time:  O(logn), where logn is the length of result strings
# Space: O(1)
#
# Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
# 
# If the fractional part is repeating, enclose the repeating part in parentheses.
# 
# For example,
# 
# Given numerator = 1, denominator = 2, return "0.5".
# Given numerator = 2, denominator = 1, return "2".
# Given numerator = 2, denominator = 3, return "0.(6)".
#

class Solution:
    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        dvd, dvs = abs(numerator), abs(denominator)
        integer, decimal, dict = "", "", {}
        
        if dvd > dvs:
            integer = str(dvd / dvs)
            dvd %= dvs
        else:
            integer = "0"
        
        if dvd > 0:
            integer += "."
        
        idx = 0
        while dvd:
            if dvd in dict:
                decimal = decimal[:dict[dvd]] + "(" + decimal[dict[dvd]:] + ")"
                break
            
            dict[dvd] = idx
            idx += 1
            
            dvd *= 10
            decimal += str(dvd / dvs)
            dvd %= dvs
        
        if (numerator > 0 and denominator < 0) or (numerator < 0 and denominator > 0): 
            return "-" + integer + decimal
        else:
            return integer + decimal

if __name__ == "__main__":
    print Solution().fractionToDecimal(1, 9)
    print Solution().fractionToDecimal(-50, 8)
    print Solution().fractionToDecimal(22, 2)
    print Solution().fractionToDecimal(-22, -2)