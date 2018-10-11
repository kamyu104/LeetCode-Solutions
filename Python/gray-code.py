from __future__ import print_function
# Time:  O(2^n)
# Space: O(1)

class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = [0]
        for i in xrange(n):
            for n in reversed(result):
                result.append(1 << i | n)
        return result

class Solution2(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        return [i >> 1 ^ i for i in xrange(1 << n)]

if __name__ == "__main__":
    print(Solution().grayCode(0))
    print(Solution().grayCode(2))

