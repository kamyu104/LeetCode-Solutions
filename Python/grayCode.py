# Time:  O(2^n)
# Space: O(1)
#
# The gray code is a binary numeral system where two successive values differ in only one bit.
# 
# Given a non-negative integer n representing the total number of bits in the code, 
# print the sequence of gray code. A gray code sequence must begin with 0.
# 
# For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
# 
# 00 - 0
# 01 - 1
# 11 - 3
# 10 - 2
# Note:
# For a given n, a gray code sequence is not uniquely defined.
# 
# For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
# 
# For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

class Solution:
    # @return a list of integers
    def grayCode(self, n):
        result = [0]
        for i in range(0, n):
            for n in reversed(result):
                result.append(1 << i | n)
        return result

# proof of closed form formula could be found here:
# http://math.stackexchange.com/questions/425894/proof-of-closed-form-formula-to-convert-a-binary-number-to-its-gray-code
class Solution2:
    # @return a list of integers
    def grayCode(self, n):
        return [i >> 1 ^ i for i in range(1 << n)]

if __name__ == "__main__":
    print Solution().grayCode(0)
    print Solution().grayCode(2)