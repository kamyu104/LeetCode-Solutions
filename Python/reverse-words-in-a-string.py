from __future__ import print_function
# Time:  O(n)
# Space: O(n)

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(reversed(s.split()))

if __name__ == '__main__':
    print(Solution().reverseWords('hello world'))

