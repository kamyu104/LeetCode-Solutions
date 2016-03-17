# Time:  O(n)
# Space: O(1)

# Given a non negative integer number num. For every numbers i
# in the range 0 <= i <= num calculate the number 
# of 1's in their binary representation and return them as an array.
#
# Example:
# For num = 5 you should return [0,1,1,2,1,2].
#
# Follow up:
#
# It is very easy to come up with a solution with run 
# time O(n*sizeof(integer)). But can you do it in 
# linear time O(n) /possibly in a single pass?
# Space complexity should be O(n).
# Can you do it like a boss? Do it without using
# any builtin function like __builtin_popcount in c++ or
# in any other language.
# Hint:
#
# 1. You should make use of what you have produced already.
# 2. Divide the numbers in ranges like [2-3], [4-7], [8-15]
#    and so on. And try to generate new range from previous.
# 3. Or does the odd/even status of the number help you in
#    calculating the number of 1s?

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0]
        for i in xrange(1, num + 1):
            res.append(res[i >> 1] + (i & 1))
        return res
