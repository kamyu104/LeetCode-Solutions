# Time:  O(n)
# Space: O(1)
#
# Given a string containing just the characters '(' and ')', 
# find the length of the longest valid (well-formed) parentheses substring.
# 
# For "(()", the longest valid parentheses substring is "()", which has length = 2.
# 
# Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
#

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        def length(it, start, c):
            depth, longest = 0, 0
            for i in it:
                if s[i] == c:
                    depth += 1
                else:
                    depth -= 1
                    if depth < 0:
                        start, depth = i, 0
                    elif depth == 0:
                        longest = max(longest, abs(i - start))
            return longest

        return max(length(xrange(len(s)), -1, '('), \
                   length(reversed(xrange(len(s))), len(s), ')'))


# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        longest, last, indices = 0, -1, []
        for i in xrange(len(s)):
            if s[i] == '(':
                indices.append(i)
            elif not indices:
                last = i
            else:
                indices.pop()
                if not indices:
                    longest = max(longest, i - last)
                else:
                    longest = max(longest, i - indices[-1])
        return longest

if __name__ == "__main__":
    print Solution().longestValidParentheses("()")
    print Solution().longestValidParentheses(")()())")
