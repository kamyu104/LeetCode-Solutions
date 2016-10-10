# Time:  O(n)
# Space: O(1)

# Write a program that outputs the string representation of numbers from 1 to n.
#
# But for multiples of three it should output “Fizz” instead of the number and for
# the multiples of five output “Buzz”. For numbers which are multiples of both three
# and five output “FizzBuzz”.
#
# Example:
#
# n = 15,
#
# Return:
# [
#     "1",
#     "2",
#     "Fizz",
#     "4",
#     "Buzz",
#     "Fizz",
#     "7",
#     "8",
#     "Fizz",
#     "Buzz",
#     "11",
#     "Fizz",
#     "13",
#     "14",
#     "FizzBuzz"
# ]

class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []

        for i in xrange(1, n+1):
            if i % 15 == 0:
                result.append("FizzBuzz")
            elif i % 5 == 0:
                result.append("Buzz")
            elif i % 3 == 0:
                result.append("Fizz")
            else:
                result.append(str(i))

        return result
