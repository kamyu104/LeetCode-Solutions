# Time:  O(n)
# Space: O(n)

# Solve a given equation and return the value of x in the form of string "x=#value".
# The equation contains only '+', '-' operation, the variable x and its coefficient.
#
# If there is no solution for the equation, return "No solution".
#
# If there are infinite solutions for the equation, return "Infinite solutions".
#
# If there is exactly one solution for the equation, we ensure that the value of x is an integer.
#
# Example 1:
# Input: "x+5-3+x=6+x-2"
# Output: "x=2"
# Example 2:
# Input: "x=x"
# Output: "Infinite solutions"
# Example 3:
# Input: "2x=x"
# Output: "x=0"
# Example 4:
# Input: "2x+3x-6x=x+2"
# Output: "x=-1"
# Example 5:
# Input: "x=x+2"
# Output: "No solution"

class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        a, b = 0, 0
        side = 1
        for eq, sign, num, isx in re.findall('(=)|([-+]?)(\d*)(x?)', equation):
            if eq:
                side = -1
            elif isx:
                a += side * int(sign + '1') * int(num or 1)
            elif num:
                b -= side * int(sign + num)
        return 'x=%d' % (b / a) if a else 'No solution' if b else 'Infinite solutions'
