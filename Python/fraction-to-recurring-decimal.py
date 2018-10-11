from __future__ import print_function
# Time:  O(logn), where logn is the length of result strings
# Space: O(1)

class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        result = ""
        if (numerator > 0 and denominator < 0) or (numerator < 0 and denominator > 0):
            result = "-"

        dvd, dvs = abs(numerator), abs(denominator)
        result += str(dvd / dvs)
        dvd %= dvs

        if dvd > 0:
            result += "."

        lookup = {}
        while dvd and dvd not in lookup:
            lookup[dvd] = len(result)
            dvd *= 10
            result += str(dvd / dvs)
            dvd %= dvs

        if dvd in lookup:
            result = result[:lookup[dvd]] + "(" + result[lookup[dvd]:] + ")"

        return result

if __name__ == "__main__":
    print(Solution().fractionToDecimal(1, 9))
    print(Solution().fractionToDecimal(-50, 8))
    print(Solution().fractionToDecimal(22, 2))
    print(Solution().fractionToDecimal(-22, -2))

