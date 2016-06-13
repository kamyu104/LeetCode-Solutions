# Time:  O(n)
# Space: O(1)

# Given an integer n, count all numbers with unique digits, x, where 0 <= x <= 10n.
#
# Example:
# Given n = 2, return 91. (The answer should be the total numbers in the range of 0 <= x <= 100,
# excluding [11,22,33,44,55,66,77,88,99,100])
#
# Hint:
# 1. A direct way is to use the backtracking approach.
# 2. Backtracking should contains three states which are (the current number,
#    number of steps to get that number and a bitmask which represent which
#    number is marked as visited so far in the current number).
#    Start with state (0,0,0) and count all valid number till we reach
#    number of steps equals to 10n.
# 3. This problem can also be solved using a dynamic programming approach and
#    some knowledge of combinatorics.
# 4. Let f(k) = count of numbers with unique digits with length equals k.
# 5. f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2)
#    [The first factor is 9 because a number cannot start with 0].

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        count, fk = 10, 9
        for k in xrange(2, n+1):
            fk *= 10 - (k-1)
            count += fk
        return count
