# Time:  O(logn), n is the value of the integer
# Space: O(1)
#
# Convert a non-negative integer to its english words representation.
# Given input is guaranteed to be less than 2^31 - 1.
#
# For example,
# 123 -> "One Hundred Twenty Three"
# 12345 -> "Twelve Thousand Three Hundred Forty Five"
# 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
#

class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "Zero"

        lookup = {0: "Zero", 1:"One", 2: "Two", 3: "Three", 4: "Four", \
                  5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine", \
                  10 : "Ten", 11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", \
                  15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen", 19: "Nineteen", \
                  20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", \
                  70: "Seventy", 80: "Eighty", 90: "Ninety"}
        unit = ["", "Thousand", "Million", "Billion"]

        res, i = [], 0
        while num != 0:
            cur = num % 1000
            if num % 1000:
                res.append(self.threedigits(cur, lookup, unit[i]))
            num //= 1000
            i += 1
        return " ".join(res[::-1])

    def threedigits(self, num, lookup, unit):
        res = []
        if num / 100 != 0:
            res = [lookup[num / 100] + " " + "Hundred"]
        if num % 100:
            res.append(self.twodigits(num % 100, lookup))
        if unit != "":
            res.append(unit)
        return " ".join(res)
    
    def twodigits(self, num, lookup):
        if num in lookup:
            return str(lookup[num])
        return " ".join([lookup[(num / 10) * 10], lookup[num % 10]])
