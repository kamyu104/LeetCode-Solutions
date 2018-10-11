from __future__ import print_function
# Time:  O(nlogn)
# Space: O(1)

class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        num = [str(x) for x in num]
        num.sort(cmp=lambda x, y: cmp(y + x, x + y))
        largest = ''.join(num)
        return largest.lstrip('0') or '0'

if __name__ == "__main__":
    num = [3, 30, 34, 5, 9]
    print(Solution().largestNumber(num))

