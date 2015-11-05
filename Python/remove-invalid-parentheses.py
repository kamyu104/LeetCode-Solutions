# Time:  O(C(n, c)), try out all possible substrings with the minimum c deletion.
# Space: O(c), the depth is at most c, and it costs n at each depth
#
# Remove the minimum number of invalid parentheses in order to
# make the input string valid. Return all possible results.
#
# Note: The input string may contain letters other than the
# parentheses ( and ).
#
# Examples:
# "()())()" -> ["()()()", "(())()"]
# "(a)())()" -> ["(a)()()", "(a())()"]
# ")(" -> [""]
#

# DFS solution.
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # Calculate the minimum left and right parantheses to remove
        def findMinRemove(s):
            left_removed, right_removed = 0, 0
            for c in s:
                if c == '(':
                    left_removed += 1
                elif c == ')':
                    if not left_removed:
                        right_removed += 1
                    else:
                        left_removed -= 1
            return (left_removed, right_removed)

        # Check whether s is valid or not.
        def isValid(s):
            sum = 0
            for c in s:
                if c == '(':
                    sum += 1
                elif c == ')':
                    sum -= 1
                if sum < 0:
                    return False
            return sum == 0

        def removeInvalidParenthesesHelper(start, left_removed, right_removed):
            if left_removed == 0 and right_removed == 0:
                tmp = ""
                for i, c in enumerate(s):
                    if i not in removed:
                        tmp += c
                if isValid(tmp):
                    res.append(tmp)
                return
    
            for i in xrange(start, len(s)):
                if right_removed == 0 and left_removed > 0 and s[i] == '(':
                    if i == start or s[i] != s[i - 1]:  # Skip duplicated.
                        removed[i] = True
                        removeInvalidParenthesesHelper(i + 1, left_removed - 1, right_removed)
                        del removed[i]
                elif right_removed > 0 and s[i] == ')':
                    if i == start or s[i] != s[i - 1]:  # Skip duplicated.
                        removed[i] = True
                        removeInvalidParenthesesHelper(i + 1, left_removed, right_removed - 1);
                        del removed[i]

        res, removed = [], {}
        (left_removed, right_removed) = findMinRemove(s)
        removeInvalidParenthesesHelper(0, left_removed, right_removed)
        return res
