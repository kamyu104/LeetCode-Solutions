# Time:  O(n)
# Space: O(1)

# Given a balanced parentheses string S,
# compute the score of the string based on the following rule:
#
# () has score 1
# AB has score A + B, where A and B are balanced parentheses strings.
# (A) has score 2 * A, where A is a balanced parentheses string.
#
# Example 1:
#
# Input: "()"
# Output: 1
# Example 2:
#
# Input: "(())"
# Output: 2
# Example 3:
#
# Input: "()()"
# Output: 2
# Example 4:
#
# Input: "(()(()))"
# Output: 6
#
# Note:
# - S is a balanced parentheses string, containing only ( and ).
# - 2 <= S.length <= 50

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3


class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        result, depth = 0, 0
        for i in xrange(len(S)):
            if S[i] == '(':
                depth += 1
            else:
                depth -= 1
                if S[i-1] == '(':
                    result += 2**depth
        return result


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = [0]
        for c in S:
            if c == '(':
                stack.append(0)
            else:
                last = stack.pop()
                stack[-1] += max(1, 2*last)
        return stack[0]
